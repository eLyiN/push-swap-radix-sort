/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 09:03:24 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/29 09:14:59 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_rrr(t_global *g)
{
	swap_rra(&g->stack_a);
	swap_rrb(&g->stack_b);
}

void	swap_ss(t_global *g)
{
	swap_sa(&g->stack_a);
	swap_sb(&g->stack_b);
}

void	both_ra(t_global *g, t_global *i)
{
	index_ra(&i->stack_a);
	swap_ra(&g->stack_a);
}

void	both_pb(t_global *g, t_global *i)
{
	index_pb(i);
	swap_pb(&g->stack_b, &g->stack_a);
}

void	both_pa(t_global *g, t_global *i)
{
	index_pa(i);
	swap_pa(&g->stack_a, &g->stack_b);
}
