/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(t_node **lst_a, t_node **lst_b)
{
	if (*lst_a && get_size(*lst_a) == 2 && !is_sorted(*lst_a))
		swap(lst_a, 'a', 1);
	if (*lst_a && !is_sorted(*lst_a))
	{
		if (get_size(*lst_a) > 3)
			pb(lst_a, lst_b);
		while (get_size(*lst_a) > 3 && !is_sorted(*lst_a))
			send_to_b(lst_a, lst_b);
		sort_three(lst_a);
		while (*lst_b)
			send_to_a(lst_a, lst_b);
		align(lst_a, lst_b);
	}
}

void	sort_three(t_node **lst)
{
	if (get_max(*lst) == *lst)
		rotate(lst, 'a', 1);
	else if (get_max(*lst) == (*lst)->next)
		rev_rotate(lst, 'a', 1);
	if ((*lst)->value > (*lst)->next->value)
		swap(lst, 'a', 1);
}
