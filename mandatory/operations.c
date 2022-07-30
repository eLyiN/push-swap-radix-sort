/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:54:03 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/30 09:29:33 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size > 1)
	{
		tmp = stack_a->array[0];
		stack_a->array[0] = stack_a->array[1];
		stack_a->array[1] = tmp;
	}
	write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size > 1)
	{
		tmp = stack_b->array[0];
		stack_b->array[0] = stack_b->array[1];
		stack_b->array[1] = tmp;
	}
	write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_pa(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

	if (stack_b->size > 0)
	{
		i = stack_a->size;
		while (i > 0)
		{
			stack_a->array[i] = stack_a->array[i - 1];
			i--;
		}
		stack_a->array[0] = stack_b->array[0];
		stack_a->size++;
		stack_b->size--;
		i = 0;
		while (i < stack_b->size)
		{
			stack_b->array[i] = stack_b->array[i + 1];
			i++;
		}
	}
	write(STDOUT_FILENO, "pa\n", 3);
}

void	swap_pb(t_stack *stack_b, t_stack *stack_a)
{
	size_t	i;

	if (stack_a->size > 0)
	{
		i = stack_b->size;
		while (i > 0)
		{
			stack_b->array[i] = stack_b->array[i - 1];
			i--;
		}
		stack_b->array[0] = stack_a->array[0];
		stack_b->size++;
		stack_a->size--;
		i = 0;
		while (i < stack_a->size)
		{
			stack_a->array[i] = stack_a->array[i + 1];
			i++;
		}
	}
	write(STDOUT_FILENO, "pb\n", 3);
}
