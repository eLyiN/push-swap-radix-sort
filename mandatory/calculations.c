/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:47:11 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/28 13:08:35 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_nb(t_stack *stack)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = stack->size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (stack->array[i] <= stack->array[j] && j < size)
			j++;
		if (j == size)
			return (stack->array[i]);
		i++;
	}
	return (0);
}

int	find_highest_nb(t_stack *stack)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = stack->size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (stack->array[i] >= stack->array[j] && j < size)
			j++;
		if (j == size)
			return (stack->array[i]);
		i++;
	}
	return (0);
}

void	new_logic(t_global *g)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	mid;

	mid = g->stack_b.size / 2;
	i = 0;
	while (g->stack_a.array[0] > g->stack_b.array[i] && i < mid)
		i++;
	j = g->stack_b.size - 1;
	while (g->stack_a.array[0] < g->stack_b.array[j] && j > mid)
		j--;
	j = (g->stack_b.size - 1) - j;
	if (i < j || i == j)
	{
		k = 0;
		while (i > 0)
		{
			swap_rb(&g->stack_b);
			i--;
			k++;
		}
		swap_pb(&g->stack_b, &g->stack_a);
		while (k > 0)
		{
			swap_rrb(&g->stack_b);
			k--;
		}
	}
	else
	{
		k = 0;
		while (j > 0)
		{
			swap_rrb(&g->stack_b);
			j--;
			k++;
		}
		swap_pb(&g->stack_b, &g->stack_a);
		while (k > 0)
		{
			swap_rb(&g->stack_b);
			k--;
		}
		swap_rb(&g->stack_b);
	}
}
