NAME = push_swap
DEPAND = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c operation.c operation2.c turck_algo_main.c \
		turck_algo_utils1.c turck_algo_utils2.c turck_algo_utils3.c

OBJS = ${SRCS:.c=.o}



all: ${NAME}

${MAME}: ${DEPAND}
	${CC} ${CFLAGS} ${SRCS} $< -o $@ 

${DEPAND}:
	cd libft
	make
	mv ${DEPAND} ..
	cd ..

clean:
	rm -rf *.o */*.o
fclean:
	rm -rf ${DEPAND}
re: fclean all
