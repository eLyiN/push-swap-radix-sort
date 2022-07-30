/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:53:26 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/30 09:56:24 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*pt;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	pt = malloc((i + 1) * sizeof(char));
	if (!(pt))
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

int	fill_stack_arg(char *ptr, t_stack *stack_a, size_t *stack_nb)
{
	int		nb;
	char	*str;

	while (*ptr)
	{
		while (*ptr && *ptr == ' ')
			ptr++;
		if (!*ptr)
			break ;
		str = ft_strdup_char(ptr, ' ');
		if (ft_atoi(str, &nb))
		{
			free(str);
			return (1);
		}
		free(str);
		if (check_double(stack_a, nb))
			return (1);
		stack_a->array[(*stack_nb)++] = nb;
		stack_a->size++;
		while (*ptr && *ptr != ' ')
			ptr++;
	}
	return (0);
}

int	evalue_arg(int ac, char *av[], t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	while (i < (size_t)ac)
	{
		ptr = av[i];
		if (fill_stack_arg(ptr, stack_a, &j))
			return (1);
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
		return (1);
	main->stack_b.array = malloc(sizeof(int) * stack_size);
	if (!main->stack_b.array)
	{
		free(main->stack_a.array);
		return (1);
	}
	if (evalue_arg(ac, av, &main->stack_a))
	{
		free(main->stack_a.array);
		free(main->stack_b.array);
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
