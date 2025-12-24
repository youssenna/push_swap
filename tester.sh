#!/bin/bash
# set -e
ARG_COUNT=$1
RANGE_START=-2932874
RANGE_END=1000000
MAX=$2
LOG_DIR=logs
mkdir -p ${LOG_DIR};
FAIL_LOG="${LOG_DIR}/fail_args.log"
BIG_OUTPUT_LOG="${LOG_DIR}/big_output.log"
LEAK_LOGS="${LOG_DIR}/leaks.log"
LOGS="$LOG_DIR/info.log"
leaks_checker() {
    valgrindOutput=$(valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARGS 2>&1)

    if echo "$valgrindOutput" | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo -n;
    else
        echo "$1" >> "$LEAK_LOGS"
    fi
}

while true; do
    ARGS=$(awk -v s="$RANGE_START" -v e="$RANGE_END" 'BEGIN {
        for (i = s; i <= e; i++) print i
    }' | shuf -n "$ARG_COUNT" | tr '\n' ' ')
    leaks_checker "$ARGS";
    OUTPUT=$(./push_swap "$ARGS")

    CHECK_RESULT=$(echo "$OUTPUT" | ./checker_linux $ARGS)

    if [[ "$CHECK_RESULT" != *"OK"* ]]; then
        echo "$ARGS" >> "$FAIL_LOG"
        echo "KO";
    fi

    LINE_COUNT=$(echo "$OUTPUT" | wc -l)

    if [[ "$LINE_COUNT" -ge $MAX ]]; then
        echo "$ARGS" >> "$BIG_OUTPUT_LOG"
    fi
    echo $ARGS >> $LOGS;
done
