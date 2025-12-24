/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truck_algo_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:25:41 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/23 19:11:54 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	ft_sort_remaining_a(t_list **stack_a)
{
	t_list *tmp;

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

t_list *find_bigger_smallest_node(t_list *src_node, t_list *stack)
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
		if (tmp->index <= stack_b_size /  2)
			tmp->cost_b = tmp->index;
		else
			tmp->cost_b = stack_b_size - tmp->index;
		if (tmp->target->index <= stack_a_size / 2)
			tmp->cost_a = tmp->target->index;
		else
			tmp->cost_a = stack_a_size - tmp->target->index;
		tmp->total_cost = tmp->cost_a + tmp->cost_b;
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

// I will applic the movements here 
void	ft_move(t_list *target_mov, t_list **stack_a, t_list **stack_b)
{
	
	int	stack_a_size;
	int	stack_b_size;
	int	i;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	if (target_mov->index <= stack_b_size / 2)
	{
		i = 0;
		while (i < target_mov->index)
		{
			ra_rb_rr(NULL, stack_b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack_b_size - target_mov->index)
		{
			rra_rrb_rrr(NULL, stack_b);
			i++;
		}
	}
	if (target_mov->target->index <= stack_a_size / 2)
	{
		i = 0;
		while (i < target_mov->target->index)
		{
			ra_rb_rr(stack_a, NULL);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack_a_size - target_mov->target->index)
		{
			rra_rrb_rrr(stack_a, NULL);
			i++;
		}
	}
	pa_pb(stack_a, stack_b, "pa");
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

//  5 3 1 2 9 6

//1   2
//3   6
//5   9

// disp stack_a->content
// disp stack_a->next->content
// disp stack_a->next->next->content
// disp stack_b->content
// disp stack_b->next->content
// disp stack_b->next->next->next->content
// disp tmp->content
// disp tmp->target->content
// disp tmp->target->index
// disp tmp->cost_b
// disp tmp->cost_a


