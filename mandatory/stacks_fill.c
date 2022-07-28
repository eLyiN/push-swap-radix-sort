/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:12:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/27 00:27:12 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(t_stack *stack_a, int nb)
{
	int	i;

	i = 0;
	while (stack_a->size > (size_t)i)
	{
		if (stack_a->array[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	process_arg(int ac, char *av[], t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	int		nb;

	i = 0;
	j = 0;
	while (i < (size_t)ac)
	{
		if (ft_atoi(av[i], &nb))
			return (1);
		if (check_duplicate(stack_a, nb))
			return (1);
		stack_a->array[j++] = nb;
		stack_a->size++;
		i++;
	}
	return (0);
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

int	stacks_fill(int ac, char *av[], t_stack *stack_a, t_stack *stack_b)
{
	size_t	stack_size;

	stack_size = stack_counter(ac, av);
	stack_a->max_size = stack_size;
	stack_b->max_size = stack_size;
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->array = malloc(sizeof(int) * stack_size);
	if (!stack_a->array)
		return (write(STDERR_FILENO, "Error\n", 6));
	stack_b->array = malloc(sizeof(int) * stack_size);
	if (!stack_b->array)
	{
		free(stack_a->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	if (process_arg(ac, av, stack_a))
	{
		free(stack_a->array);
		free(stack_b->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}
