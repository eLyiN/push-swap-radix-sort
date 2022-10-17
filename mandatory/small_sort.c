/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:10:23 by aarribas          #+#    #+#             */
/*   Updated: 2022/10/17 17:01:19 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_three_nb(t_stack *stk)
{
	if (stk->array[0] > stk->array[1] && stk->array[0] < stk->array[2])
		swap_sa(stk);
	else if (stk->array[0] > stk->array[1] && stk->array[1] > stk->array[2])
	{
		swap_sa(stk);
		swap_rra(stk);
	}
	else if (stk->array[0] > stk->array[1] && stk->array[1] < stk->array[2])
		swap_ra(stk);
	else if (stk->array[0] < stk->array[1] && stk->array[0] < stk->array[2])
	{
		swap_sa(stk);
		swap_ra(stk);
	}
	else if (stk->array[0] < stk->array[1] && stk->array[0] > stk->array[2])
		swap_rra(stk);
	return (0);
}

void	perform_rest_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	size;

	swap_pa(stack_a, stack_b);
	size = stack_a->size;
	i = 1;
	while (stack_a->array[0] > stack_a->array[i] && i != size)
		i++;
	if (i == size)
		swap_ra(stack_a);
}

int	find_last_pos(t_stack *stack_a)
{
	int	i;
	int	j;
	int	size;

	size = stack_a->size - 1;
	i = 1;
	j = size - 1;
	while (stack_a->array[0] > stack_a->array[i] && i < size)
		i++;
	while (stack_a->array[size] > stack_a->array[j] && j != 0)
		j--;
	if (j == 0 && stack_a->array[size] > stack_a->array[j])
	{
		swap_rra(stack_a);
		return (1);
	}
	if (i == size && stack_a->array[0] > stack_a->array[i])
		return (1);
	return (0);
}

int	find_first_pos(t_stack *stack_a)
{
	int	i;
	int	j;
	int	size;

	size = stack_a->size - 1;
	i = 1;
	j = size - 1;
	while (stack_a->array[0] < stack_a->array[i] && i < size)
		i++;
	while (stack_a->array[size] < stack_a->array[j] && j != 0)
		j--;
	if (j == 0 && stack_a->array[size] < stack_a->array[j])
	{
		swap_rra(stack_a);
		return (1);
	}
	if (i == size && stack_a->array[0] < stack_a->array[i])
		return (1);
	return (0);
}

void	start_sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->array[0] > stack_a->array[1])
			swap_sa(stack_a);
		return ;
	}
	while (stack_a->size > 3)
	{
		if (find_first_pos(stack_a))
			swap_pb(stack_b, stack_a);
		else if (find_last_pos(stack_a))
			swap_pb(stack_b, stack_a);
		else if (stack_a->size > 3)
			swap_ra(stack_a);
	}
	if (check_sorted_nb(stack_a))
		sort_three_nb(stack_a);
	while (stack_b->size > 0)
		perform_rest_sort_a(stack_a, stack_b);
	return ;
}
