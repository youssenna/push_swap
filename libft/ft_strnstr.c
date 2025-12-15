/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:11:54 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/26 14:48:11 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] == to_find[j] && to_find[j])
			j++;
		if (to_find[j] == '\0')
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
