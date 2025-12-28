/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:25:43 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 15:50:19 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// this function you will find it on operation.c
// and operation2.c file 
int		swap_2_top_elem(t_list **head);
void	sa_sb_ss(t_list **a, t_list **b);
void	pa_pb(t_list **a, t_list **b, char *op);
void	ra_rb_rr(t_list **a, t_list **b);
void	rra_rrb_rrr(t_list **a, t_list **b);

// this functions on "turck_algo_utils1.c"
void	ft_sort_remaining_a(t_list **stack_a);
t_list	*find_small_node(t_list *stack);
t_list	*find_bigger_smallest_node(t_list *src_node, t_list *stack);
void	ft_find_targets_node(t_list *stack_a, t_list **stack_b);
int		ft_abs(int nb);

// this functions on "turck_algo_utils2.c"
int		ft_max(int a, int b);
void	ft_calculate_top_cost(t_list *stack_a, t_list *stack_b);
t_list	*find_min_moves(t_list *stack);
void	ft_operation(char *op, int is_stack_a, t_list **stack);
void	ft_move_node_to_top(int node_index, t_list **stack, int sta_len, int a);

// this functions on "turck_algo_utils2.c"
void	ft_normal_move(t_list *target_mov, t_list **stack_a, t_list **stack_b);
void	ft_rr_operation_a(int cost_a, int cost_b, t_list **st_a, t_list **st_b);
void	ft_rr_operation_b(int cost_a, int cost_b, t_list **st_a, t_list **st_b);
void	ft_rr_until_top(int cost_a, int cost_b, t_list **st_a, t_list **st_b);
void	ft_rrr_operation_a(int cos_a, int cost_b, t_list **st_a, t_list **st_b);

// this functions on "turck_algo_main.c"
void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b);

#endif