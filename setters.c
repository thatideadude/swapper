/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_node *lst_a, t_node *lst_b, t_node *start)
{
	lst_a->cost = lst_a->index;
	if (lst_b)
	{
		if (lst_a->index > get_size(start) / 2)
			lst_a->cost = get_size(start) - lst_a->index;
		if (lst_a->target->index <= get_size(lst_b) / 2)
			lst_a->cost += lst_a->target->index;
		else if (lst_a->target->over)
			lst_a->cost += get_size(lst_b) - lst_a->target->index;
	}
}

void	set_index(t_node **lst)
{
	int		i;
	int		lst_size;
	t_node	*tmp;

	tmp = *lst;
	i = 0;
	lst_size = get_size(*lst);
	while (tmp)
	{
		tmp->index = i;
		tmp->over = 0;
		if (i > lst_size / 2)
			tmp->over = 1;
		tmp = tmp->next;
		++i;
	}
}

void	set_list(t_node *lst_a, t_node *lst_b, char list)
{
	t_node	*start;

	start = lst_a;
	set_index(&lst_a);
	set_index(&lst_b);
	while (lst_a)
	{
		if (list == 'a')
		{
			lst_a->target = get_closest_smaller(lst_a->value, lst_b);
			set_cost(lst_a, lst_b, start);
		}
		else
			lst_a->target = get_closest_bigger(lst_a->value, lst_b);
		lst_a = lst_a->next;
	}
}

void	set_stacks(t_node **lst_a, t_node **lst_b)
{
	set_list(*lst_a, *lst_b, 'a');
	set_list(*lst_b, *lst_a, 'b');
}
