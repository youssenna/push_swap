/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:23:53 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/26 18:33:21 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_2char_equal(char c1, char *str)
{
	if (*str == c1)
		return (1);
	return (0);
}


size_t	ft_count_words(char const *str, char *sep)
{
	size_t	words;
	int		i;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_2char_equal(str[i], sep))
			i++;
		if (str[i])
			words++;
		while (str[i] && !ft_is_2char_equal(str[i], sep))
			i++;
		while (str[i] && ft_is_2char_equal(str[i], sep))
			i++;
	}
	return (words);
}

int	ft_next_word_len(char const *str, int *str_index, char *sep)
{
	int	len;

	len = 0;
	while (str[*str_index] && ft_is_2char_equal(str[*str_index], sep))
		(*str_index)++;
	while (str[*str_index] && !ft_is_2char_equal(str[*str_index], sep))
	{
		len++;
		(*str_index)++;
	}
	return (len);
}

void	free_2d_arr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char *sep)
{
	char	**strs;

	size_t words_count, (i);
	if (!s)
		return (NULL);
	int next_word_len, (s_index);
	words_count = ft_count_words(s, sep);
	strs = malloc((words_count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	s_index = 0;
	while (i < words_count)
	{
		next_word_len = ft_next_word_len(s, &s_index, sep);
		strs[i] = ft_substr(s, s_index - next_word_len, next_word_len);
		if (!strs[i])
		{
			free_2d_arr(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
