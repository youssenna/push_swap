/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:56:54 by yousenna          #+#    #+#             */
/*   Updated: 2025/11/27 13:50:21 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_out(const char *str, int *i, va_list *str_ptr)
{
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		if (str[*i] == 'x')
			return (ft_puthex(va_arg(*str_ptr, size_t), 'x'));
		else
			return (ft_puthex(va_arg(*str_ptr, size_t), 'X'));
	}
	else if (str[*i] == 'i' || str[*i] == 'd')
		return (ft_putnbr(va_arg(*str_ptr, int)));
	else if (str[*i] == 's')
		return (ft_putstr(va_arg(*str_ptr, char *)));
	else if (str[*i] == 'c')
		return (ft_putchar(va_arg(*str_ptr, int)));
	else if (str[*i] == 'p')
		return (ft_putaddr(va_arg(*str_ptr, void *)));
	else if (str[*i] == 'u')
		return (ft_putunsig(va_arg(*str_ptr, unsigned int)));
	else if (str[*i] == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_check_stock(int stock)
{
	if (stock == -1)
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	str_ptr;

	int count, (i), stock;
	if (write(1, "1", 0) == -1 || !str)
		return (-1);
	count = 0;
	va_start(str_ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			stock = ft_print_out(str, &i, &str_ptr);
			if (!ft_check_stock(stock))
				return (-1);
			count += stock;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(str_ptr);
	return (count);
}
