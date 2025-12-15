/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:59:24 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/21 21:13:21 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nememb, size_t size)
{
	size_t	size_total;
	void	*buffer;

	if (size != 0 && nememb > SIZE_MAX / size)
		return (NULL);
	size_total = nememb * size;
	buffer = malloc(size_total);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size_total);
	return (buffer);
}
