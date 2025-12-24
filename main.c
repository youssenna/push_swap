#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	ft_check_repeat(t_list *head)
{
	t_list	*tmp;
	t_list	*stock_head;

	stock_head = head;
	if (!head)
		return (0);
	tmp = head;
	head = head->next;
	while (head)
	{
		if (head->content == tmp->content)
			return (ft_lstclear(&stock_head), 1);
		head = head->next;
		if (head == NULL && tmp->next != NULL)
		{
			tmp = tmp->next;
			head = tmp->next;
		}
	}
	return (0);
}

// her I push to the stack and I check is valid int on the 2_d array 
// that's split return
int	ft_push_back(char **ints, t_list **head)
{
	int		nb;
	t_list	*node;
	int		is_valid;
	int		i;

	i = 0;
	while (ints[i] && *ints[i])
	{
		nb = ft_atoi(ints[i], &is_valid);
		node = ft_lstnew(nb);
		if (!node || !is_valid)
		{
			if (!is_valid)
				free(node);
			return (ft_lstclear(head), 0);
		}
		ft_lstadd_back(head, node);
		i++;
	}
	return (1);
}

int	ft_check_is_valid_input(int ac, char **av, t_list **head)
{
	int	i;
	char	**ints;

	i = 0;
	while (i < ac - 1)
	{
		ints = ft_split(av[i + 1], " \t\n\v\f\r");
		if (!ints || !ints[0])
			return (ft_lstclear(head), free(ints), 0);
		if (!ft_push_back(ints, head))
			return (free_2d_arr(ints) ,0);
		if (ft_check_repeat(*head))
			return (free_2d_arr(ints), 0);
		free_2d_arr(ints);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	if (ac > 1)
	{
		if (!ft_check_is_valid_input(ac, av, &stack_a))
			return (ft_putstr_fd("Error\n", 2), (1));

		ft_sort_stack_a(&stack_a, &stack_b);
	// ft_printf("\n------stack a-----------\n");
	// ft_lstshow(stack_a);
	// ft_sort_stack_a(&stack_a, &stack_b);
	// ft_printf("\n------stack a after sort 3 number-----------\n");
	// ft_lstshow(stack_a);
		ft_lstclear(&stack_a);
		
	}
	return (0);
}


// a.out " 25 762 836" "   187" " 98 38 -97"

// a 
// 3 1 2

// b 2 1 -3