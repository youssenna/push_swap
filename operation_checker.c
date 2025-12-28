/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:19:27 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 23:37:58 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_2_top_elem(t_list **head)
{
	t_list	*tmp;
	t_list	*third_node;

	if (!head || !(*head) || !(*head)->next)
		return (0);
	tmp = *head;
	third_node = (*head)->next->next;
	*head = (*head)->next;
	(*head)->next = tmp;
	tmp->next = third_node;
	return (1);
}

// this function work is sa sb ss operations 
void	sa_sb_ss(t_list **a, t_list **b)
{
	// if ((!b && !a) || (!(*a)->next && !(*b)->next))
		// return ;
	if (!b)
		swap_2_top_elem(a);
	else if (!a)
		swap_2_top_elem(b);
	else
	{
		swap_2_top_elem(a);
		swap_2_top_elem(b);
	}
}

// this function work is pa and pb operations 
void	pa_pb(t_list **a, t_list **b, char *op)
{
	t_list	*tmp;

	if (!ft_strncmp(op, "pa", 2))
	{
		if (b && *b)
		{
			tmp = *b;
			*b = (*b)->next;
			tmp->next = *a;
			*a = tmp;
		}
	}
	else if (!ft_strncmp(op, "pb", 2))
	{
		if (a && *a)
		{
			tmp = *a;
			*a = (*a)->next;
			tmp->next = *b;
			*b = tmp;
		}
	}
}

int	rotate(t_list **head)
{
	t_list	*tmp;

	if (!head || !(*head) || !(*head)->next)
		return (0);
	tmp = *head;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = tmp;
	*head = tmp->next;
	tmp->next = NULL;
	return (1);
}

// this function work is ra rb rr operations 
void	ra_rb_rr(t_list **a, t_list **b)
{
	if (!b)
		rotate(a);
	else if (!a)
		rotate(b);
	else
	{
		rotate(a);
		rotate(b);
	}
}
