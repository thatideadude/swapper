/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 08:56:37 by marcemon          #+#    #+#             */
/*   Updated: 2025/06/01 08:56:37 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				over;
	int				cost;
	struct s_node	*target;
	struct s_node	*next;
}				t_node;

//makers
t_node	*create_node(int value);
t_node	*make_stack(char **array, int size);

//parsers
long	ft_atol(char *str);
void	add_last(t_node **lst, long value);

//getters
t_node	*get_closest_bigger(int value, t_node *lst);
t_node	*get_closest_smaller(int value, t_node *lst);
t_node	*get_node(int value, t_node *lst);
t_node	*get_cheapest(t_node *lst);
t_node	*get_min(t_node *lst);
t_node	*get_max(t_node *lst);
int		get_size(t_node *lst);

//pushers
void	pa(t_node **lst_a, t_node **lst_b);
void	pb(t_node **lst_a, t_node **lst_b);

//setters
void	set_list(t_node *lst_a, t_node *lst_b, char list);
void	set_stacks(t_node **lst_a, t_node **lst_b);
void	set_cost(t_node *lst_a, t_node *lst_b, t_node *start);
void	set_index(t_node **lst);

//movers
void	rotate(t_node **stack, char name, int print);
void	rev_rotate(t_node **stack, char name, int print);
void	swap(t_node **lst, char stack, int print);
void	double_rotate(t_node **lst_a, t_node **lst_b, t_node *target);
void	bring_to_top(t_node **lst_a, t_node **lst_b, t_node *t, char stack);
void	send_to_b(t_node **lst_a, t_node **lst_b);
void	send_to_a(t_node **lst_a, t_node **lst_b);
void	align(t_node **lst_a, t_node **lst_b);

//sorters
void	push_swap(t_node **lst_a, t_node **lst_b);
void	sort_three(t_node **lst);

//helpers
int		is_sorted(t_node *lst);
int		is_space(char c);
int		is_valid_number(char *str);
int		is_valid_value(long value, t_node *stack);
void	free_stack(t_node **lst);

//split
int		count_words(char *str);
char	*make_string(char *str);
char	**split(char *str);
char	**free_strings(char **strings);

void	fillArrayWithUniqueRandoms(int *array, int size);

#endif
