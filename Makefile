all:
	cd libft; make; cd ../ft_printf; make; cd ..; cc libft/libft.a *.c

clean:
	rm libft/*.o ft_printf/*.o
