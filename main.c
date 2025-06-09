/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*lst_a;
	t_node	*lst_b;
	char	**strings;

	lst_b = 0;
	strings = 0;
	if (!argv[1] || !argv[1][0])
	{
		write(1, "Error\n", 6);
		exit(1);
		return (1);
	}
	else if (argc == 2 && count_words(argv[1]))
	{
		strings = split(argv[1]);
		lst_a = make_stack(strings, count_words(argv[1]));
	}
	else
		lst_a = make_stack(&argv[1], argc - 1);
	push_swap(&lst_a, &lst_b);
	free_strings(strings);
	free_stack(&lst_a);
	free_stack(&lst_b);
	return (0);
}
