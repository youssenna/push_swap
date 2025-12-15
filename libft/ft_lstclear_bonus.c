/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:11:33 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/14 18:49:24 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!lst || !del)
		return ;
	prev = *lst;
	while ((*lst))
	{
		*lst = (*lst)->next;
		ft_lstdelone(prev, del);
		prev = *lst;
	}
	*lst = NULL;
}
