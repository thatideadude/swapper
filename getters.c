/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_closest_bigger(int value, t_node *lst)
{
	long	tmp;
	t_node	*start;

	start = lst;
	tmp = LONG_MAX;
	while (lst)
	{
		if (lst->value > value && (long)lst->value < tmp)
			tmp = lst->value;
		lst = lst->next;
	}
	if (tmp == LONG_MAX)
		return (get_min(start));
	return (get_node((int)tmp, start));
}

t_node	*get_closest_smaller(int value, t_node *lst)
{
	long	tmp;
	t_node	*start;

	start = lst;
	tmp = LONG_MIN;
	while (lst)
	{
		if (lst->value < value && (long)lst->value > tmp)
			tmp = lst->value;
		lst = lst->next;
	}
	if (tmp == LONG_MIN)
		return (get_max(start));
	return (get_node((int)tmp, start));
}

t_node	*get_node(int value, t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	while (lst)
	{
		if (lst->value == value)
			return (lst);
		lst = lst->next;
	}
	return (tmp);
}

t_node	*get_cheapest(t_node *lst)
{
	int		cost;
	t_node	*tmp;

	tmp = NULL;
	cost = INT_MAX;
	while (lst)
	{
		if (lst->cost < cost)
		{
			tmp = lst;
			cost = lst->cost;
		}
		lst = lst->next;
	}
	return (tmp);
}
