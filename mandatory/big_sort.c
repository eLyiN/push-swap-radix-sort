/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:11:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/10/17 16:54:16 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	start_sort_big(t_global *global)
{
	t_global	index;

	index.stack_a.max_size = global->stack_a.size;
	index.stack_a.size = 0;
	index.stack_b.max_size = global->stack_b.size;
	index.stack_b.size = 0;
	index.stack_a.array = malloc(sizeof(int) * global->stack_a.size);
	if (!index.stack_a.array)
		return (write(STDERR_FILENO, "Error\n", 6));
	index.stack_b.array = malloc(sizeof(int) * global->stack_a.size);
	if (!index.stack_b.array)
	{
		free(index.stack_a.array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	simple_indexation(&global->stack_a, &index);
	radix_and_push(global, &index);
	free(index.stack_a.array);
	free(index.stack_b.array);
	return (0);
}

void	radix_and_push(t_global *g, t_global *index)
{
	int	max_bits;
	int	i;
	int	j;
	int	nb;
	int	size;

	size = g->stack_a.size;
	max_bits = 0;
	while (((index->stack_a.size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			nb = index->stack_a.array[0];
			if (((nb >> i) & 1) == 1)
				both_ra(g, index);
			else
				both_pb(g, index);
		}
		while (index->stack_b.size > 0)
			both_pa(g, index);
	}
}

void	simple_indexation(t_stack *stack_a, t_global *index)
{
	size_t	i;
	size_t	j;
	int		lw_nb;
	int		high_nb;

	lw_nb = find_smallest_nb(stack_a);
	high_nb = find_highest_nb(stack_a);
	j = 0;
	while (lw_nb != high_nb + 1)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (stack_a->array[i] == lw_nb)
			{
				index->stack_a.array[i] = j;
				index->stack_a.size++;
				j++;
			}
			i++;
		}
		lw_nb++;
	}
}
