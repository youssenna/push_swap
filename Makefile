NAME = push_swap
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =  operation.c operation2.c turck_algo_main.c \
		turck_algo_utils1.c turck_algo_utils2.c turck_algo_utils3.c push_swap_main.c

OBJS = $(SRCS:.c=.o)

BONUS_NAME = checker

BONUS_SRCS = checker_main.c checker_utils.c operation_checker.c operation2_checker.c \
			 get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -L${LIBFT_DIR} -lft -o ${NAME}

${LIBFT}:
	$(MAKE) -C ${LIBFT_DIR} bonus


bonus: all ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS} 
	${CC} ${CFLAGS} ${BONUS_OBJS} -L${LIBFT_DIR} -lft -o $@

# ${BONUS_OBJS}: ${BONUS_SRCS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS} ${BONUS_OBJS}
	$(MAKE) -C libft clean
fclean: clean
	$(MAKE) -C libft fclean
re: fclean all


.PHONY = all bonus clean fclean re
# handling of relinking
.SECONDARY: