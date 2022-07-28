/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:11:02 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/28 14:08:08 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	start_sort_big(t_global *global)
{
	t_global	index;

	index.stack_a.array = malloc(sizeof(int) * global->stack_a.size);
	if (!index.stack_a.array)
		return (write(STDERR_FILENO, "Error\n", 6));
	simple_indexation(&global->stack_a, index);
	radix_and_push(global, index);
	return (0);
}

void	radix_and_push(t_global *g, int *index)
{
	int	max_bits;
	int	i;
	int	j;
	int	k;
	int	nb;

	max_bits = 0;
	while (((g->stack_a.max_size - 1) >> max_bits) != 0)
		max_bits++;
	printf("MAXBITS:%d\n", max_bits);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < (int)g->stack_a.size)
		{
			nb = index[0];
			printf("Index[0] en Radix_sort:%d\n", index[0]);
			if (((nb >> i) & 1) == 1)
			{
				index_ra(index, &g->stack_a);
				swap_ra(&g->stack_a);
			}
			else
			{
				index_clear(index, &g->stack_a);
				swap_pb(&g->stack_b, &g->stack_a);
			}
			j++;
		}
		k = -1;
		while (++k < (int)g->stack_b.size)
			printf("STACK_B[%d]: %d\n", k, g->stack_b.array[k]);
		k = -1;
		while (g->stack_b.size > 0)
			swap_pa(&g->stack_a, &g->stack_b);
		while (++k < (int)g->stack_a.size)
			printf("STACK_A[%d]: %d\n", k, g->stack_a.array[k]);
		i++;
	}
}

void	simple_indexation(t_stack *stack_a, int *index)
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
				index[i] = j;
				j++;
			}
			i++;
		}
		lw_nb++;
	}
	j = -1;
	while (++j < stack_a->size)
		printf("INDEX[%ld]: %d\n", j, index[j]);
}

//Hay que mover varias veces los numeros de un lado a otro por lo cual
//la indexacion no se puede completar teniendo 1 stack, vamos a usar
//un t_global para crear el index y almacenarlo ahi, luego recreamos
//las funciones para index y hacemos los mismos movimientos en el original
//y en el index. FIN.