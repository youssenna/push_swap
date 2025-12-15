#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	ft_free_content(void *content)
{
	// free(content);
}

int ft_check_is_valid_ints(char ***ints, t_list **head)
{
	int i;
	int j;
	long nb;
	int is_valid;
	
	j = 0;
	while (ints[j])
	{
		i = 0;
		while (ints[j][i])
		{
			nb = ft_atoi(ints[j][i], &is_valid);
			if (is_valid)
			{
				ft_lstadd_back(head, ft_lstnew((void*) &nb));
			}
			else
				return (ft_lstclear(head, ft_free_content), 0);
			i++;
		}
		j++;
	}
	return (1);
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
		if (*((int *)head->content) == *((int *)tmp->content))
			return (ft_lstclear(&head, ft_free_content), 1);
		head = head->next;
		if (head == NULL && tmp->next != NULL)
		{
			tmp = tmp->next;
			head = tmp->next;
		}
	}
	return (0);
}

int	ft_check_is_valid_input(int ac, char **av, t_list **head)
{
	size_t	i;
	char	***ints;

	ints = malloc(sizeof(char **) * ac);

	i = 0;
	while (i < ac)
	{
		ints[i] = ft_split(av[i + 1], ' ');
		i++;
	}
	ints[i] = NULL;
	if (!ft_check_is_valid_ints(ints, head))
		return (0);
	if (!ft_check_repeat(*head))
		return (0);
	return 1;
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
		
	}
	return (0);
}


// a.out " 25 762 836" "   187" " 98 38 -97"

// a -3 1 2

// b 2 1 -3