/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:45:35 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/21 18:53:51 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

// void ft_(unsigned int a, char *c)
// {
// 	*c = *c + a;
// }

// int main()
// {
// 	void (*f)(unsigned int, char*) = &ft_;
// 	char str[] = "AAAAAAAAAAAAAA";
// 	ft_striteri(str, f);
// 	printf("%s", str);
// }
