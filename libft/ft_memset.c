/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:04:00 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/22 21:42:20 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*str1;

	if (!str)
		return (str);
	str1 = (char *)str;
	while (n > 0)
	{
		str1[n - 1] = c;
		n--;
	}
	return (str);
}
