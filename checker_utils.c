/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:22:08 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/28 01:51:41 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_execute_op(t_list **stack_a, t_list **stack_b, char *op)
{
	if (ft_strlen(op) == 3 && !ft_strncmp(op, "sa\n", 3))
		return (sa_sb_ss(stack_a, NULL), 1);
	else if (ft_strlen(op) == 3 && !ft_strncmp(op, "sb\n", 3))
		return (sa_sb_ss(NULL, stack_b), 1);
	else if (ft_strlen(op) == 3 && !ft_strncmp(op, "ss\n", 3))
		return (sa_sb_ss(stack_a, stack_b), 1);
	else if (ft_strlen(op) == 3 && !ft_strncmp(op, "pa\n", 3))
		return (pa_pb(stack_a, stack_b, "pa\n"), 1);
	else if (ft_strlen(op) == 3 && !ft_strncmp(op, "pb\n", 3))
		return (pa_pb(stack_a, stack_b, "pb\n"), 1);
	else if (ft_strlen(op) == 3 && !ft_strncmp(op, "ra\n", 3))
		return (ra_rb_rr(stack_a, NULL), 1);
	else if (ft_strlen(op) == 3 && !ft_strncmp(op, "rb\n", 3))
		return (ra_rb_rr(NULL, stack_b), 1);
	else if (ft_strlen(op) == 3 && !ft_strncmp(op, "rr\n", 3))
		return (ra_rb_rr(stack_a, stack_b), 1);
	else if (ft_strlen(op) == 4 && !ft_strncmp(op, "rra\n", 4))
		return (rra_rrb_rrr(stack_a, NULL), 1);
	else if (ft_strlen(op) == 4 && !ft_strncmp(op, "rrb\n", 4))
		return (rra_rrb_rrr(NULL, stack_b), 1);
	else if (ft_strlen(op) == 4 && !ft_strncmp(op, "rrr\n", 4))
		return (rra_rrb_rrr(stack_a, stack_b), 1);
	return (0);
}

void	ft_check_opearations(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_execute_op(stack_a, stack_b, line))
		{
			free(line);
			ft_lstclear(stack_a);
			ft_lstclear(stack_b);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}
