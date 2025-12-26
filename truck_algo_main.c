/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truck_algo_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:25:41 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/26 20:18:12 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	ft_sort_remaining_a(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (ft_lstsize(tmp) == 1)
		return ;
	if (ft_lstsize(tmp) == 2)
	{
		if (tmp->content > tmp->next->content)
			sa_sb_ss(&tmp, NULL);
		*stack_a = tmp;
		return ;
	}
	if (tmp->content > tmp->next->content
		&& tmp->content > tmp->next->next->content)
		ra_rb_rr(&tmp, NULL);
	else if (tmp->next->content > tmp->content
		&& tmp->next->content > tmp->next->next->content)
		rra_rrb_rrr(&tmp, NULL);
	if (tmp->content > tmp->next->content)
		sa_sb_ss(&tmp, NULL);
	*stack_a = tmp;
}

t_list	*find_small_node(t_list *stack)
{
	t_list	*small_node;
	int		i;

	i = 0;
	small_node = stack;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
		if (stack && stack->content < small_node->content)
			small_node = stack;
	}
	return (small_node);
}

// if i found the bigger smallest node I return it else i return NULL

t_list	*find_bigger_smallest_node(t_list *src_node, t_list *stack)
{
	t_list	*big_small_node;
	int		i;

	i = 0;
	big_small_node = NULL;
	while (stack)
	{
		if (stack->content > src_node->content)
		{
			big_small_node = stack;
			break ;
		}
		stack->index = i++;
		stack = stack->next;
	}
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
		if (stack && stack->content < big_small_node->content
			&& stack->content > src_node->content)
			big_small_node = stack;
	}
	return (big_small_node);
}

/*	on this function for every element at stack b I will search for 
 *	it's target node on stack a
 => the target node for every node it's the bigger smallest content 
	on stack a if not found it ;
	- the target node will be the smallest content on stack a.
*/

void	ft_find_targets_node(t_list *stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->target = find_bigger_smallest_node(tmp, stack_a);
		if (!tmp->target)
			tmp->target = find_small_node(stack_a);
		tmp->index = i++;
		tmp = tmp->next;
	}
}

// the top cost is how many move every node at every stack need
// to be on the top

int	ft_abs(int nb)
{
	return ((nb > 0) * nb + (nb < 0) * -nb);
}

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
