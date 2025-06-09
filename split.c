/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 525/06/01 08:56:37 by marcemon          #+#    #+#              */
/*   Updated: 525/06/01 08:56:37 by marcemon         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	i;
	int	words;

	if (!str)
		return (0);
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i])
			++words;
		while (str[i] != ' ' && str[i])
			++i;
	}
	return (words);
}

char	*make_string(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i])
		++i;
	new = malloc(i + 1);
	if (!new)
		return (new);
	i = 0;
	while (str[i] != ' ' && str[i])
	{
		new[i] = str[i];
		++i;
	}
	new[i] = 0;
	return (new);
}

char	**split(char *str)
{
	int		i;
	int		j;
	char	**strings;

	i = 0;
	j = 0;
	strings = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!strings)
		return (strings);
	while (i < count_words(str))
	{
		while (str[j] == ' ')
			++j;
		if (str[j])
		{
			strings[i] = make_string(&str[j]);
			if (!strings[i])
				return (free_strings(strings));
			++i;
		}
		while (str[j] != ' ' && str[j])
			++j;
	}
	strings[i] = 0;
	return (strings);
}

char	**free_strings(char **strings)
{
	int	i;

	i = 0;
	if (strings)
		while (strings[i])
			free(strings[i++]);
	free(strings);
	return (strings);
}
