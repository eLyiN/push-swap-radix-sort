/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:47:11 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/29 10:01:13 by aarribas         ###   ########.fr       */
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
