all:
	cd libft; make; cd ../ft_printf; make; cd ..; cc libft/libft.a ft_printf/libftprintf.a libft/libft.h ft_printf/ft_printf.h main.c *.c
clean:
	rm libft/*.o ft_printf/*.o libft/*.a ft_printf/*.a
