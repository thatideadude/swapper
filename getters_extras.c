/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_retrievers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min(t_node *lst)
{
	int		min;
	t_node	*tmp;

	min = INT_MAX;
	tmp = lst;
	while (lst)
	{
		if (lst->value < min)
		{
			min = lst->value;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

t_node	*get_max(t_node *lst)
{
	int		max;
	t_node	*tmp;

	max = INT_MIN;
	tmp = lst;
	while (lst)
	{
		if (lst->value > max)
		{
			max = lst->value;
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

int	get_size(t_node *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst)
	{
		++lst_size;
		lst = lst->next;
	}
	return (lst_size);
}
