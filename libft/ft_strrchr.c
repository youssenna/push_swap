/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:46:17 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/18 11:38:24 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char	*last;

	if (!str)
		return (NULL);
	last = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last = (char *)str;
		str++;
	}
	if (*str == (char)c)
		last = (char *)str;
	return (last);
}
