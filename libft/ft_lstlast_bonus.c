/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:02:13 by yousenna          #+#    #+#             */
/*   Updated: 2025/10/27 09:26:46 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*
void	ft_lstshow(t_list *head)
{
	int	i;

	if (!head)
		return ;
	i = 0;
	while (head)
	{
		printf("lst[%d]--->%s----->", i + 1, (char *)head->content);
		i++;
		head = head->next;
	}
}

int	main(void)
{
	char	**arr;
	int		i;
	t_list	*head;

	arr = ft_split("\
	this_is_the_last
	node hello world\
	 morooco codding \
	with moljlaba", ' ');
	i = 0;
	head = NULL;
	while (i < 7)
	{
		ft_lstadd_front(&head, ft_lstnew(arr[i]));
		i++;
	}
	ft_lstshow(head);
	printf("\n---------------------------------\n");
	ft_lstshow(ft_lstlast(head));
}
*/
