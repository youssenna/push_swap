/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:05:53 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/19 13:08:37 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	size_t total_len, (s1_len), (s2_len);
	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	new_str = malloc(total_len);
	if (!new_str)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			ft_strlcpy(new_str, s2, s2_len + 1);
		else
			ft_strlcpy(new_str, s1, s1_len + 1);
	}
	else
	{
		ft_strlcpy(new_str, s1, s1_len + 1);
		ft_strlcat(new_str, s2, total_len);
	}
	return (new_str);
}
