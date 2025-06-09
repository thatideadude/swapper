/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_movers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotate(t_node **lst_a, t_node **lst_b, t_node *target)
{
	if (target->over)
	{
		rev_rotate(lst_a, 'a', 0);
		rev_rotate(lst_b, 'b', 0);
		write(1, "rrr\n", 4);
	}
	else
	{
		rotate(lst_a, 'a', 0);
		rotate(lst_b, 'b', 0);
		write(1, "rr\n", 3);
	}
}

void	rotate(t_node **stack, char name, int print)
{
	t_node	*tmp;
	t_node	*first;
	t_node	*lst;

	lst = *stack;
	if (!lst || !lst->next)
		return ;
	tmp = lst;
	first = lst->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
	lst->next = NULL;
	if (print && name == 'a')
		write(1, "ra\n", 3);
	else if (print && name == 'b')
		write(1, "rb\n", 3);
	*stack = first;
}

void	rev_rotate(t_node **stack, char name, int print)
{
	t_node	*prev;
	t_node	*last;
	t_node	*lst;

	lst = *stack;
	if (!lst || !lst->next)
		return ;
	prev = NULL;
	last = lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = lst;
	*stack = last;
	if (print && name == 'a')
		write(1, "rra\n", 4);
	else if (print && name == 'b')
		write(1, "rrb\n", 4);
}

void	swap(t_node **lst, char name, int print)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = *lst;
	b = (*lst)->next;
	c = (*lst)->next->next;
	*lst = b;
	b->next = a;
	a->next = c;
	if (print && name == 'a')
		write(1, "sa\n", 3);
	else if (print && name == 'b')
		write(1, "sb\n", 3);
}
