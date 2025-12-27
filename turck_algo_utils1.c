/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turck_algo_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:44:06 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 12:50:55 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
