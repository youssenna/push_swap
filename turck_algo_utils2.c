/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turck_algo_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:11:06 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 12:51:04 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (a >= b)
			return (a);
		return (b);
	}
	else
	{
		if (ft_abs(a) >= ft_abs(b))
			return (ft_abs(a));
		return (ft_abs(b));
	}
	return (0);
}

void	ft_calculate_top_cost(t_list *stack_a, t_list *stack_b)
{
	int		stack_a_size;
	int		stack_b_size;
	t_list	*tmp;

	stack_a_size = ft_lstsize(stack_a);
	stack_b_size = ft_lstsize(stack_b);
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->index <= stack_b_size / 2)
			tmp->cost_b = tmp->index;
		else
			tmp->cost_b = -(stack_b_size - tmp->index);
		if (tmp->target->index <= stack_a_size / 2)
			tmp->cost_a = tmp->target->index;
		else
			tmp->cost_a = -(stack_a_size - tmp->target->index);
		if ((tmp->cost_a >= 0 && tmp->cost_b >= 0)
			|| (tmp->cost_a < 0 && tmp->cost_b < 0))
			tmp->total_cost = ft_max(tmp->cost_a, tmp->cost_b);
		else
			tmp->total_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		tmp = tmp->next;
	}
}

t_list	*find_min_moves(t_list *stack)
{
	t_list	*min_total_cost;

	min_total_cost = stack;
	while (stack)
	{
		stack = stack->next;
		if (stack && stack->total_cost < min_total_cost->total_cost)
			min_total_cost = stack;
	}
	return (min_total_cost);
}

void	ft_operation(char *op, int is_stack_a, t_list **stack)
{
	if (ft_strncmp("rotat", op, 5) == 0)
	{
		if (is_stack_a)
			ra_rb_rr(stack, NULL);
		else
			ra_rb_rr(NULL, stack);
	}
	else if (ft_strncmp("rrotat", op, 6) == 0)
	{
		if (is_stack_a)
			rra_rrb_rrr(stack, NULL);
		else
			rra_rrb_rrr(NULL, stack);
	}
}

void	ft_move_node_to_top(int node_index, t_list **stack, int sta_len, int a)
{
	int	i;

	if (node_index <= sta_len / 2)
	{
		i = 0;
		while (i < node_index)
		{
			ft_operation("rotat", a, stack);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < sta_len - node_index)
		{
			ft_operation("rrotat", a, stack);
			i++;
		}
	}
}
