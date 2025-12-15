NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putaddr.c ft_putchar.c ft_puthex.c \
		ft_putnbr.c ft_putstr.c ft_putunsig.c

HEADER = ft_printf.h
OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c ${HEADER}
	$(CC) ${CFLAGS} -c $< -o $@
clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re

#handling relinking
.SECONDARY:
