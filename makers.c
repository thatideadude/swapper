/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 08:56:37 by marcemon          #+#    #+#             */
/*   Updated: 2025/06/01 08:56:37 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (new);
	new->value = value;
	new->index = 0;
	new->over = 0;
	new->cost = 0;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

t_node	*make_stack(char **array, int size)
{
	int		i;
	t_node	*start;
	t_node	*current;
	long	value;

	if (!array || !array[0] || size < 1)
		return (NULL);
	value = ft_atol(array[0]);
	if (!is_valid_number(array[0]) || !is_valid_value(value, NULL))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	start = create_node(value);
	if (!start)
		return (NULL);
	current = start;
	i = 0;
	while (++i < size)
	{
		if (!is_valid_number(array[i]))
		{
			free_stack(&start);
			write(2, "Error\n", 6);
			return (NULL);
		}
		value = ft_atol(array[i]);
		if (!is_valid_value(value, start))
		{
			free_stack(&start);
			write(2, "Error\n", 6);
			return (NULL);
		}
		current->next = create_node(value);
		if (!current->next)
		{
			free_stack(&start);
			return (NULL);
		}
		current = current->next;
	}
	return (start);
}
