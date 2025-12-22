/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:19:27 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/17 18:49:20 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

int	swap_2_top_elem(t_list **head)
{
	t_list	*tmp;
	t_list	*third_node;

	if (!head || !(*head)->next)
		return 0;
	tmp = *head;
	third_node = (*head)->next->next;
	*head = (*head)->next;
	(*head)->next = tmp;
	tmp->next = third_node;
	return 1;
}

void	sa_sb_ss(t_list **a, t_list **b)
{
	if (!b)
	{
		if (swap_2_top_elem(a))
			ft_putendl_fd("sa", 1);
	}
	else if (!a)
	{
		if (swap_2_top_elem(b))
			ft_putendl_fd("sb", 1);
	}
	else
	{
		if (swap_2_top_elem(a) && swap_2_top_elem(b))
			ft_putendl_fd("ss", 1);
	}
}

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
			ft_putendl_fd("pa", 1);		
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
			ft_putendl_fd("pb", 1);		
		}
	}
}

int	rotate(t_list **head)
{
	t_list	*tmp;
	
	if (!head || !(*head)->next)
		return 0;
	tmp = *head;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = tmp;
	*head = tmp->next;
	tmp->next = NULL;
	return (1);	
}

void	ra_rb_rr(t_list **a, t_list **b)
{
	if (!b)
	{
		if (rotate(a))
			ft_putendl_fd("ra", 1);
	}
	else if (!a)
	{
		if (rotate(b))
			ft_putendl_fd("rb", 1);
	}
	else
	{
		if (rotate(a) && rotate(b))
			ft_putendl_fd("rr", 1);
	}
}