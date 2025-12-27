/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:36:42 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/27 12:36:45 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_is_valid_int(const char *str, int i, long *result, int *is_valid)
{
	int	digit_start;

	digit_start = i;
	*is_valid = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + (str[i] - '0');
		if (*result > 2147483648)
			*is_valid = 0;
		i++;
	}
	if (str[i] != '\0')
		*is_valid = 0;
}

long	ft_atoi(const char *str, int *is_valid_int)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	if (!str)
		return (0);
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!str[i])
		return (*is_valid_int = 0, (0));
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (*is_valid_int = 0, 0);
	ft_is_valid_int(str, i, &result, is_valid_int);
	if (sign * result > 2147483647 || sign * result < -2147483648)
		*is_valid_int = 0;
	return (sign * result);
}
