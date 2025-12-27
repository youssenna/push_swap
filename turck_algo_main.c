/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turck_algo_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:25:41 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 12:49:56 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_operation_b(int cost_a, int cost_b, t_list **st_a, t_list **st_b)
{
	int	min;
	int	max;
	int	i;

	min = cost_b;
	max = cost_a;
	i = 0;
	while (i < min)
	{
		rra_rrb_rrr(st_a, st_b);
		i++;
	}
	while (i < max)
	{
		rra_rrb_rrr(NULL, st_b);
		i++;
	}
}

void	ft_rrr_until_top(int cost_a, int cost_b, t_list **st_a, t_list **st_b)
{
	if (cost_a > cost_b)
		ft_rrr_operation_a(cost_a, cost_b, st_a, st_b);
	else
		ft_rrr_operation_b(cost_b, cost_a, st_a, st_b);
}

void	ft_move(t_list *target_mov, t_list **stack_a, t_list **stack_b)
{
	if (target_mov->cost_a > 0 && target_mov->cost_b > 0)
	{
		ft_rr_until_top(target_mov->cost_a, target_mov->cost_b,
			stack_a, stack_b);
		pa_pb(stack_a, stack_b, "pa");
		return ;
	}
	else if (target_mov->cost_a < 0 && target_mov->cost_b < 0)
	{
		ft_rrr_until_top(ft_abs(target_mov->cost_a),
			ft_abs(target_mov->cost_b), stack_a, stack_b);
		pa_pb(stack_a, stack_b, "pa");
		return ;
	}
	else
		ft_normal_move(target_mov, stack_a, stack_b);
}

void	ft_mov_small_node_to_top(t_list *target, t_list **stack_a)
{
	int		stack_a_size;
	int		i;

	stack_a_size = ft_lstsize(*stack_a);
	if (target->index <= stack_a_size / 2)
	{
		i = 0;
		while (i < target->index)
		{
			ra_rb_rr(stack_a, NULL);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack_a_size - target->index)
		{
			rra_rrb_rrr(stack_a, NULL);
			i++;
		}
	}
}

void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*target_moves;

	*stack_b = NULL;
	while (ft_lstsize(*stack_a) > 3)
		pa_pb(stack_a, stack_b, "pb");
	ft_sort_remaining_a(stack_a);
	if (ft_lstsize(*stack_a) <= 3 && ft_lstsize(*stack_b) == 0)
		return ;
	while (*stack_b)
	{
		ft_find_targets_node(*stack_a, stack_b);
		ft_calculate_top_cost(*stack_a, *stack_b);
		target_moves = find_min_moves(*stack_b);
		ft_move(target_moves, stack_a, stack_b);
	}
	ft_mov_small_node_to_top(find_small_node(*stack_a), stack_a);
}
