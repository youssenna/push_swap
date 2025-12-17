#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int ft_check_is_valid_ints(char ***ints, t_list **head)
{
	int i;
	int j;
	int nb;
	int is_valid;
	t_list *node;
	
	j = 0;
	while (ints[j])
	{
		i = 0;
		while (ints[j][i])
		{
			nb = ft_atoi(ints[j][i], &is_valid);
			node = ft_lstnew(nb);
			if (!node || !is_valid)
				return (free(node), ft_lstclear(head), 0);
			ft_lstadd_back(head, node);
			free(ints[j][i]);
			i++;
		}
		free(ints[j]);
		j++;
	}
	return (free(ints), 1);
}

void	ft_check_is_valid_int(char *str, int i, long *result, int *is_valid);

int	ft_check_repeat(t_list *head)
{
	int nb;
	t_list *tmp;

	if (!head)
		return (1);
	tmp = head;
	head = head->next;
	while (head)
	{
		if (head->content == tmp->content)
			return (ft_lstclear(&head), 1);
		head = head->next;
		if (head == NULL && tmp->next != NULL)
		{
			tmp = tmp->next;
			head = tmp->next;
		}
	}
	return (0);
}

int	ft_push_back(int **ints, t_list **head)
{
	char	*stock_add;
	int		nb;
	t_list	*node;
	int		is_valid;

	while (*ints)
	{
		nb = ft_atoi(*ints, &is_valid);
		node = ft_lstnew(nb);
		if (!node || !is_valid)
		{
			if (!is_valid)
				free(node);
			return (ft_lstclear(head), 0);
		}
		ft_lstadd_back(head, node);
		stock_add = *ints;
		(*ints)++;
		free(stock_add);
	}
	return (free(ints), 1);
}

int	ft_check_is_valid_input(int ac, char **av, t_list **head)
{
	size_t	i;
	char	**ints;

	if (!ints)
		return (free(ints), 0);
	i = 0;
	while (i < ac - 1)
	{
		ints = ft_split(av[i + 1], ' ');
		if (!ints)
			return (0);
		ft_push_back(ints, head);
		i++;
	}
	ints[i] = NULL;
	if (!ft_check_is_valid_ints(ints, head))
		return (ft_lstclear(head), 0);
	if (ft_check_repeat(*head))
		return (ft_lstclear(head), 0);
	return (1);
}

int main(int ac, char **av)
{
	t_list *head;

	head = NULL;
	if (ac > 1)
	{
		if (!ft_check_is_valid_input(ac, av, &head))
			return (ft_putstr_fd("Error\n", 2), (1));
		ft_lstshow(head);
		// ft_lstclear(&head);
		
	}
	return (0);
}


// a.out " 25 762 836" "   187" " 98 38 -97"

// a -3 1 2

// b 2 1 -3