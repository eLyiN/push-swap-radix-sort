/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:53:26 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/29 23:52:04 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	evalue_arg(int ac, char *av[], t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	int		nb;

	i = 0;
	j = 0;
	while (i < (size_t)ac)
	{
		if (ft_atoi(av[i], &nb))
			return (1);
		if (check_double(stack_a, nb))
			return (1);
		stack_a->array[j++] = nb;
		stack_a->size++;
		i++;
	}
	return (0);
}

int	stacks_fill(int ac, char *av[], t_global *main)
{
	size_t	stack_size;

	stack_size = stack_counter(ac, av);
	main->stack_a.max_size = stack_size;
	main->stack_b.max_size = stack_size;
	main->stack_a.size = 0;
	main->stack_b.size = 0;
	main->stack_a.array = malloc(sizeof(int) * stack_size);
	if (!main->stack_a.array)
		return (write(STDERR_FILENO, "Error\n", 6));
	main->stack_b.array = malloc(sizeof(int) * stack_size);
	if (!main->stack_b.array)
	{
		free(main->stack_a.array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	if (evalue_arg(ac, av, &main->stack_a))
	{
		free(main->stack_a.array);
		free(main->stack_b.array);
		write(STDERR_FILENO, "Error3\n", 6);
		return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_global	main;
	char		*buff;

	if (ac < 2)
		return (1);
	if (stacks_fill(--ac, &av[1], &main))
		return (1);
	buff = ft_calloc(2, sizeof(char));
	if (!buff)
		return (1);
	if (read_instructions(&main, buff))
		return (1);
	if (run_program(&main))
		return (1);
	if (!check_sorted_nb(&main.stack_a) && main.stack_b.size == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	freedom(&main);
	return (0);
}
