/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **lst_a, t_node **lst_b)
{
	t_node	*tmp;

	if (!lst_b || !*lst_b)
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node **lst_a, t_node **lst_b)
{
	t_node	*tmp;

	if (!lst_a || !*lst_a)
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
	write(1, "pb\n", 3);
}
