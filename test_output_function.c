/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_output_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:10:19 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/22 04:12:16 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	ft_lstshow(t_list *lst)
{
	int	i;

	if (!lst)
	{
		ft_printf("list is empty\n");
		return ;
	}
	i = 0;
	while (lst)
	{
		ft_printf("element[%d]: %d\n", ++i, lst->content);
		ft_printf("target_node: %d\n", lst->target->content);
		lst = lst->next;
	}
}
// a.out 1 2 3 "615 5556"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ft_generat_random_number_no_dep() {
    int array[RAND_NB_GEN];
    int i, j, temp;

    // Fill array with values 0 to 12
    for (i = 0; i < RAND_NB_GEN; i++) {
        array[i] = i;
    }

    // Shuffle the array
    srand(time(NULL));
    for (i = RAND_NB_GEN - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Print the shuffled array
    for (i = 0; i < RAND_NB_GEN; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}   

// void	ft_test_operation(t_list **head, t_list **lst)
// {
// 	ft_printf("\n--------befor sa-------\n");
// 	ft_printf("\n-----head----\n");
// 	ft_lstshow(head);
// 	ft_printf("\n-----lst----\n");
// 	ft_lstshow(lst);
// 	ft_printf("\n--------after ra-------\n");
// 	sa_sb_ss(&head, NULL);
// 	pa_pb(&head, &lst, "pb");
// 	pa_pb(&head, &lst, "pb");
// 	pa_pb(&head, &lst, "pb");
// 	ra_rb_rr(&head, &lst);
// 	rra_rrb_rrr(&head, &lst);
// 	sa_sb_ss(&head, NULL);
// 	pa_pb(&head, &lst, "pa");
// 	pa_pb(&head, &lst, "pa");
// 	pa_pb(&head, &lst, "pa");
// 	ft_printf("\n-----head->b-----\n");
// 	ft_lstshow(head);
// 	ft_printf("\n--------lst->a-------\n");
// 	ft_lstshow(lst);
// 	ft_lstclear(&head);
// }