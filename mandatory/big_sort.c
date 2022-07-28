/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:11:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/28 11:50:04 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_phase(t_program *s100, t_global *g, int *index)
{
	if (g->stack_a.size > 2)
	{
		if (s100->hold_first < s100->hold_second
			|| s100->hold_first == s100->hold_second)
		{
			while (s100->hold_first != 0)
			{
				swap_ra(&g->stack_a);
				index_ra(index, &g->stack_a);
				s100->hold_first--;
			}
		}
		else
		{
			while (s100->hold_second != 0)
			{
				swap_rra(&g->stack_a);
				index_ra(index, &g->stack_a);
				s100->hold_second--;
			}
		}
	}
	chk_b_nd_push(g, index);
	s100->chnk_count++;
}

int	push_b_phase(t_program *s100, t_global *g)
{
	if (s100->hold_first < s100->hold_second
		|| s100->hold_first == s100->hold_second)
	{
		while (s100->hold_first != 0)
		{
			swap_rb(&g->stack_b);
			s100->hold_first--;
		}
	}
	else
	{
		while (s100->hold_second != 0)
		{
			swap_rrb(&g->stack_b);
			s100->hold_second--;
		}
	}
	swap_pa(&g->stack_a, &g->stack_b);
	return (0);
}

int	start_sort_big(t_global *global)
{
	t_program	s100;
	int			*index;

	start_program(&s100, global);
	s100.low_nb = find_smallest_nb(&index);
	s100.high_nb = find_highest_nb(&index);
	index = malloc(sizeof(int) * global->stack_a.size);
	if (!index)
		return (write(STDERR_FILENO, "Error\n", 6));
	simple_indexation(&s100, &global->stack_a, index);
	radix_and_push(&s100, &global, index);
	return (0);
}

void	radix_and_push(t_program *s100, t_global *g, int *index)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = 0;
	while ((s100->high_nb >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < g->stack_a.size - 1)
		{
			if ()
				j++;
		}
		i++;
	}
}

void	simple_indexation(t_program *s100, t_stack *stack_a, int *index)
{
	size_t	i;
	size_t	j;
	int		lw_nb;

	lw_nb = s100->low_nb;
	j = 0;
	while (lw_nb != s100->high_nb + 1)
	{
		i = 0;
		while (i < stack_a->size)
		{
			if (stack_a->array[i] == lw_nb)
			{
				index[i] = j;
				j++;
			}
			i++;
		}
		lw_nb++;
	}
}

void	get_holds(t_program *s100, t_stack *stack, int *index)
{
	size_t	i;
	size_t	mid;
	int		status;

	mid = stack->size / 2;
	i = 0;
	while (i < mid && status == 0)
	{
		if (index[i] < (int)s100->chnk_max_stack)
		{
			s100->hold_first = i;
			status = 1;
		}
		i++;
	}
	status = 0;
	i = stack->size;
	while (i > mid && status == 0)
	{
		if (index[i] < (int)s100->chnk_max_stack)
		{
			s100->hold_second = i - mid;
			status = 1;
		}
		i--;
	}
}
