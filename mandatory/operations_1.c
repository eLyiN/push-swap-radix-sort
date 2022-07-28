/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:34:15 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/22 09:53:03 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_ra(t_stack *stack_a)
{
	size_t	i;
	int		tmp;

	tmp = stack_a->array[0];
	i = 0;
	while (i < (stack_a->size - 1))
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[i] = tmp;
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	swap_rb(t_stack *stack_b)
{
	size_t	i;
	int		tmp;

	tmp = stack_b->array[0];
	i = 0;
	while (i < (stack_b->size - 1))
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[i] = tmp;
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	swap_rra(t_stack *stack_a)
{
	size_t	i;
	int		tmp;

	tmp = stack_a->array[stack_a->size - 1];
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = tmp;
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	swap_rrb(t_stack *stack_b)
{
	size_t	i;
	int		tmp;

	tmp = stack_b->array[stack_b->size - 1];
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = tmp;
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}
