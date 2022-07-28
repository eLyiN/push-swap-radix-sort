/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:34:15 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/28 23:44:19 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_ra(t_stack *index_a)
{
	size_t	i;
	int		tmp;
	size_t	size;

	size = index_a->size;
	tmp = index_a->array[0];
	i = 0;
	while (i < (size - 1))
	{
		index_a->array[i] = index_a->array[i + 1];
		i++;
	}
	index_a->array[i] = tmp;
}

void	index_rra(t_stack *index_a)
{
	size_t	i;
	int		tmp;
	size_t	size;

	size = index_a->size;
	tmp = index_a->array[size - 1];
	i = size;
	while (i > 0)
	{
		index_a->array[i] = index_a->array[i - 1];
		i--;
	}
	index_a->array[0] = tmp;
}

void	index_pb(t_global *index)
{
	size_t	i;

	if (index->stack_a.size > 0)
	{
		i = index->stack_b.size;
		while (i > 0)
		{
			index->stack_b.array[i] = index->stack_b.array[i - 1];
			i--;
		}
		index->stack_b.array[0] = index->stack_a.array[0];
		index->stack_b.size++;
		index->stack_a.size--;
		i = 0;
		while (i < index->stack_a.size)
		{
			index->stack_a.array[i] = index->stack_a.array[i + 1];
			i++;
		}
	}
}

void	index_pa(t_global *index)
{
	size_t	i;

	if (index->stack_b.size > 0)
	{
		i = index->stack_a.size;
		while (i > 0)
		{
			index->stack_a.array[i] = index->stack_a.array[i - 1];
			i--;
		}
		index->stack_a.array[0] = index->stack_b.array[0];
		index->stack_a.size++;
		index->stack_b.size--;
		i = 0;
		while (i < index->stack_b.size)
		{
			index->stack_b.array[i] = index->stack_b.array[i + 1];
			i++;
		}
	}
}
