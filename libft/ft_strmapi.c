/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:50:29 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/26 17:30:20 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}

// char ft_(unsigned int a, char c)
// {
// 	return (c + a);
// }

// int main()
// {
// 	char (*f)(unsigned int, char) = &ft_;
// 	char *str = ft_strmapi("AAAAAAAAAAAAAA", f);
// 	printf("%s", str);
// }
