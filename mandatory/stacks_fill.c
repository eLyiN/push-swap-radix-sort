/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:12:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/10/17 17:20:40 by aarribas         ###   ########.fr       */
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
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	fill_stack_arg(char *ptr, t_stack *stack_a, size_t *stack_nb)
{
	int		nb;
	char	*str;

	while (*ptr)
	{
		while (*ptr && *ptr == ' ')
			ptr++;
		if (!*ptr)
			return (EXIT_FAILURE);
		str = ft_strdup_char(ptr, ' ');
		if (ft_atoi(str, &nb))
		{
			free(str);
			return (EXIT_FAILURE);
		}
		free(str);
		if (check_duplicate(stack_a, nb))
			return (EXIT_FAILURE);
		stack_a->array[(*stack_nb)++] = nb;
		stack_a->size++;
		while (*ptr && *ptr != ' ')
			ptr++;
	}
	return (EXIT_SUCCESS);
}

int	process_arg(int ac, char *av[], t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	while (i < (size_t)ac)
	{
		ptr = av[i];
		if (ptr[0] == '\0')
			return (EXIT_FAILURE);
		if (fill_stack_arg(ptr, stack_a, &j))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
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
		return (EXIT_FAILURE);
	}
	if (process_arg(ac, av, stack_a))
	{
		free(stack_a->array);
		free(stack_b->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
