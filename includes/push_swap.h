/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:06 by aarribas          #+#    #+#             */
/*   Updated: 2022/10/17 16:56:30 by aarribas         ###   ########.fr       */
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
char		*ft_strdup_char(const char *str, char stop);
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
void		swap_rrr(t_global *g);
void		swap_rr(t_global *g);
void		swap_ss(t_global *g);
void		both_ra(t_global *g, t_global *i);
void		both_pb(t_global *g, t_global *i);
void		both_pa(t_global *g, t_global *i);

/*small_sort.c*/

void		start_sort_small(t_stack *stack_a, t_stack *stack_b);
int			check_sorted_nb(t_stack *stack_a);
void		perform_rest_sort_a(t_stack *stack_a, t_stack *stack_b);
int			find_last_pos(t_stack *stack_a);
int			find_first_pos(t_stack *stack_a);
int			sort_three_nb(t_stack *stack_a);

/*calculations.c*/

int			find_smallest_nb(t_stack *stack);
int			find_highest_nb(t_stack *stack);

/*big_sort.c*/
int			start_sort_big(t_global *global);
void		simple_indexation(t_stack *stack_a, t_global *index);
void		radix_and_push(t_global *g, t_global *index);

#endif