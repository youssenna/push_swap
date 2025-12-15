/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:24:51 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/27 09:24:17 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_n_len(long nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

void	ft_putn_in_str(char *str, long nbr, int nb_len)
{
	while (nbr > 0)
	{
		str[nb_len - 1] = nbr % 10 + '0';
		nb_len--;
		nbr = nbr / 10;
	}
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*str;
	long	nb;

	nb = n;
	n_len = ft_calc_n_len(nb);
	str = malloc(n_len + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		str[n_len] = '\0';
		return (str);
	}
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	ft_putn_in_str(str, nb, n_len);
	str[n_len] = '\0';
	return (str);
}
