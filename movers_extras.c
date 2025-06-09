/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_movers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	bring_to_top(t_node **lst_a, t_node **lst_b, t_node *target, char stack)
{
	set_stacks(lst_a, lst_b);
	while (*lst_a != target)
	{
		if (target->over)
			rev_rotate(lst_a, stack, 1);
		else
			rotate(lst_a, stack, 1);
	}
}

void	send_to_b(t_node **lst_a, t_node **lst_b)
{
	t_node	*target;

	set_stacks(lst_a, lst_b);
	target = get_cheapest(*lst_a);
	if (target->over == target->target->over)
		while (*lst_a != target && *lst_b != target->target)
			double_rotate(lst_a, lst_b, target);
	bring_to_top(lst_a, lst_b, target, 'a');
	bring_to_top(lst_b, lst_a, target->target, 'b');
	pb(lst_a, lst_b);
}

void	send_to_a(t_node **lst_a, t_node **lst_b)
{
	set_stacks(lst_a, lst_b);
	bring_to_top(lst_a, lst_b, (*lst_b)->target, 'a');
	pa(lst_a, lst_b);
}

void	align(t_node **lst_a, t_node **lst_b)
{
	t_node	*min;

	set_stacks(lst_a, lst_b);
	min = get_min(*lst_a);
	while (*lst_a != min)
	{
		if (min->over)
			rev_rotate(lst_a, 'a', 1);
		else
			rotate(lst_a, 'a', 1);
	}
}
