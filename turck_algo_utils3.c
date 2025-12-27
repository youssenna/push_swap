/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turck_algo_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:10:39 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 12:51:14 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// I will applic the movements here 
void	ft_normal_move(t_list *target_mov, t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	ft_move_node_to_top(target_mov->index, stack_b, stack_b_size, 0);
	ft_move_node_to_top(target_mov->target->index, stack_a, stack_a_size, 1);
	pa_pb(stack_a, stack_b, "pa");
}

void	ft_rr_operation_a(int cost_a, int cost_b, t_list **st_a, t_list **st_b)
{
	int	min;
	int	max;
	int	i;

	min = cost_b;
	max = cost_a;
	i = 0;
	while (i < min)
	{
		ra_rb_rr(st_a, st_b);
		i++;
	}
	while (i < max)
	{
		ra_rb_rr(st_a, NULL);
		i++;
	}
}

void	ft_rr_operation_b(int cost_a, int cost_b, t_list **st_a, t_list **st_b)
{
	int	min;
	int	max;
	int	i;

	min = cost_b;
	max = cost_a;
	i = 0;
	while (i < min)
	{
		ra_rb_rr(st_a, st_b);
		i++;
	}
	while (i < max)
	{
		ra_rb_rr(NULL, st_b);
		i++;
	}
}

void	ft_rr_until_top(int cost_a, int cost_b, t_list **st_a, t_list **st_b)
{
	if (cost_a > cost_b)
		ft_rr_operation_a(cost_a, cost_b, st_a, st_b);
	else
		ft_rr_operation_b(cost_b, cost_a, st_a, st_b);
}

void	ft_rrr_operation_a(int cost_a, int cost_b, t_list **st_a, t_list **st_b)
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
		rra_rrb_rrr(st_a, NULL);
		i++;
	}
}
