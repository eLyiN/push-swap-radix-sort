/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:52:14 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/29 22:56:22 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	check_sorted_nb(t_stack *stack_a)
{
	size_t	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->array[i] < stack_a->array[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_double(t_stack *stack_a, int nb)
{
	size_t	i;

	i = 0;
	while (stack_a->size > i)
	{
		if (stack_a->array[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

void	freedom(t_global *main)
{
	free(main->stack_a.array);
	free(main->stack_b.array);
	free(main->checker.inst);
}

int	count_instr(const char *str, char c)
{
	int	i;
	int	substr;
	int	in_word;

	i = 0;
	substr = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			in_word = 0;
		}
		else
		{
			if (in_word == 0)
			{
				in_word = 1;
				substr++;
			}
			i++;
		}
	}
	return (substr);
}

size_t	stack_counter(int ac, char *av[])
{
	size_t	size;
	size_t	i;
	size_t	j;

	size = 0;
	i = 0;
	while (i < (size_t)ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!j || av[i][j - 1] == ' ') && av[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}
