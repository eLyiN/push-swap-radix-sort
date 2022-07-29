/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:55:03 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/29 23:47:30 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int			*array;
	size_t		size;
	size_t		max_size;
}				t_stack;

typedef struct s_program
{
	char		**inst;
	int			inst_size;
}				t_program;

typedef struct s_global
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_program	checker;
}				t_global;

/*imported libft*/

int				ft_atoi(const char *str, int *nb);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *str1, const char *str2);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nitems, size_t size);

/* operations.c operations_1.c operations_2.c*/

void			swap_sa(t_stack *stack_a);
void			swap_sb(t_stack *stack_b);
void			swap_pa(t_stack *stack_a, t_stack *stack_b);
void			swap_pb(t_stack *stack_b, t_stack *stack_a);
void			swap_ra(t_stack *stack_a);
void			swap_rb(t_stack *stack_b);
void			swap_rra(t_stack *stack_a);
void			swap_rrb(t_stack *stack_b);
void			swap_rrr(t_global *g);
void			swap_ss(t_global *g);

/* checker.c */

int				evalue_arg(int ac, char *av[], t_stack *stack_a);
int				stacks_fill(int ac, char *av[], t_global *main);

/* instructions.c */

int				process_instr(t_global *main, char *instruction);
int				read_instructions(t_global *main, char *buff);
int				run_program(t_global *main);

/* utils.c */

int				check_sorted_nb(t_stack *stack_a);
int				check_double(t_stack *stack_a, int nb);
void			freedom(t_global *main);
int				count_instr(const char *str, char c);
size_t			stack_counter(int ac, char *av[]);

#endif