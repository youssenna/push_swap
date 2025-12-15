/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:36:52 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/17 22:18:02 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_islower() function is in file "ft_isalpha.c"
int	ft_toupper(int c)
{
	if (ft_islower(c))
		c = c - 32;
	return (c);
}
