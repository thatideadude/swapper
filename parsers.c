/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 08:56:37 by marcemon          #+#    #+#             */
/*   Updated: 2025/06/01 08:56:37 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	sum;
	int		sign;
	int		i;

	if (!str)
		return (LONG_MAX);
	sum = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		sum = sum * 10 + str[i++] - '0';
	return (sum * sign);
}

void	add_last(t_node **lst, long value)
{
	if (value < INT_MIN || value > INT_MAX)
	{
		free_stack(lst);
		lst = NULL;
		write(1, "error\n", 6);
		return ;
	}
	while ((*lst)->next)
	{
		if ((*lst)-> value == value)
		{
			write(1, "error\n", 6);
			return ;
		}
		*lst = (*lst)->next;
	}
	(*lst)->next = create_node(value);
}
