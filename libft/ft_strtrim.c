/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:34:40 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/20 17:47:47 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_c_in_str(char const *set, char c)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_calc_sides_len(char const *s1, char const *set,
		unsigned int *left_side_len)
{
	int				i;
	unsigned int	len;
	size_t			s1_len;

	if (!s1 || !set)
		return (0);
	s1_len = ft_strlen(s1);
	len = 0;
	i = 0;
	while (ft_is_c_in_str(set, s1[i++]))
		len++;
	*left_side_len = len;
	i = s1_len - 1;
	while (i >= 0 && ft_is_c_in_str(set, s1[i]))
	{
		len++;
		if (i == 0)
			break ;
		i--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			sides_len;
	unsigned int	left_side_len;
	char			*trimed_str;
	size_t			trimed_str_len;

	if (!s1 || !set)
		return (NULL);
	sides_len = ft_calc_sides_len(s1, set, &left_side_len);
	trimed_str_len = ft_strlen(s1) - sides_len;
	if (trimed_str_len <= 0)
	{
		trimed_str = ft_strdup("");
		if (!trimed_str)
			return (NULL);
	}
	else
	{
		trimed_str = ft_substr(s1, left_side_len, trimed_str_len);
		if (!trimed_str)
			return (NULL);
	}
	return (trimed_str);
}
