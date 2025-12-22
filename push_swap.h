#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

# define RAND_NB_GEN 100

void	ft_lstshow(t_list *lst);
void	ft_test_operation(t_list **head, t_list **lst);

void	ft_check_is_valid_int(char *str, int i, long *result, int *is_valid);
int		swap_2_top_elem(t_list **head);
void	sa_sb_ss(t_list **a, t_list **b);
void	pa_pb(t_list **a, t_list **b, char *op);
void	ra_rb_rr(t_list **a, t_list **b);
void	rra_rrb_rrr(t_list **a, t_list **b);
void	ft_sort_remaining_a(t_list **stack_a);
void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b);



# endif