/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:18:34 by yousenna          #+#    #+#             */
/*   Updated: 2025/11/27 13:53:12 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_add_hex(unsigned long nb)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += ft_put_add_hex(nb / 16);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_putaddr(void *p)
{
	int	count;

	if (!p)
		return (ft_putstr("(nil)"));
	count = 0;
	if (!p)
		return (0);
	count = ft_putstr("0x") + ft_put_add_hex((unsigned long)p);
	return (count);
}
