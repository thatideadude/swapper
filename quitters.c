#include "push_swap.h"

int	exit_err(t_node *lst_a, t_node *lst_b, char **strings, int print)
{
	free_stack(&lst_a);
	free_stack(&lst_b);
	free_strings(strings);
	if (print)
	{
		write(1, "Error\n", 6);
		write(3, "Error\n", 6);
	}
	exit(1);
	return (1);
}
