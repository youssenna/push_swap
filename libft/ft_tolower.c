/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:13:52 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/17 22:17:55 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_isupper() function is in file "ft_isalpha.c"
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c = c + 32;
	return (c);
}
