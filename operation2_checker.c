/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:25:22 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 23:40:59 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*stock_head;

	if (!head || !(*head) || !(*head)->next)
		return (0);
	stock_head = *head;
	while ((*head)->next && (*head)->next->next)
		*head = (*head)->next;
	tmp = (*head)->next;
	(*head)->next = NULL;
	tmp->next = stock_head;
	*head = tmp;
	return (1);
}

// this function work is rra rrb rrr operations 
void	rra_rrb_rrr(t_list **a, t_list **b)
{
	if (!b)
		reverse_rotate(a);
	else if (!a)
		reverse_rotate(b);
	else
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
