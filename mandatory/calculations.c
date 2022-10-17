/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:47:11 by aarribas          #+#    #+#             */
/*   Updated: 2022/10/17 16:54:08 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_nb(t_stack *stack)
{
	size_t	i;
	int		min;

	i = 0;
	min = stack->array[i];
	while (i < stack->max_size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}

int	find_highest_nb(t_stack *stack)
{
	size_t	i;
	int		max;

	i = 0;
	max = stack->array[0];
	while (i < stack->max_size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}
