/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:06 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/28 23:50:27 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*array;
	size_t	size;
	size_t	max_size;
}			t_stack;

typedef struct s_global
{
	t_stack	stack_a;
	t_stack	stack_b;
}			t_global;

typedef struct s_program
{
	int		low_nb;
	int		high_nb;
}			t_program;

/* stacks_fill.c */

int			check_duplicate(t_stack *stack_a, int nb);
int			fill_stack(char *ptr_av, t_stack *stack_a, size_t *stack_nb);
int			process_arg(int ac, char *av[], t_stack *stack_a);
size_t		stack_counter(int ac, char *av[]);
int			stacks_fill(int ac, char *av[], t_stack *stack_a, t_stack *stack_b);

/* operations.c operations_1.c operations_2.c*/
void		swap_sa(t_stack *stack_a);
void		swap_sb(t_stack *stack_b);
void		swap_pa(t_stack *stack_a, t_stack *stack_b);
void		swap_pb(t_stack *stack_b, t_stack *stack_a);
void		swap_ra(t_stack *stack_a);
void		swap_rb(t_stack *stack_b);
void		swap_rra(t_stack *stack_a);
void		swap_rrb(t_stack *stack_b);
void		index_pa(t_global *index);
void		index_pb(t_global *index);
void		index_ra(t_stack *index_a);
void		index_rra(t_stack *index_a);

/*small_sort.c*/

int			start_sort_small(t_stack *stack_a, t_stack *stack_b);
int			check_sorted_nb(t_stack *stack_a);
void		perform_rest_sort_a(t_stack *stack_a, t_stack *stack_b);
int			find_last_pos(t_stack *stack_a);
int			find_first_pos(t_stack *stack_a);
int			sort_three_nb(t_stack *stack_a);

/*calculations.c*/

int			chk_b_nd_push(t_global *g, int *index);
void		place_bottom(t_stack *stack);
void		place_top(t_program *s100, t_stack *stack);
int			find_smallest_nb(t_stack *stack);
int			find_highest_nb(t_stack *stack);
void		new_logic(t_global *g);

/*big_sort.c*/
int			start_sort_big(t_global *global);
void		simple_indexation(t_stack *stack_a, t_global *index);
void		radix_and_push(t_global *g, t_global *index);

#endif