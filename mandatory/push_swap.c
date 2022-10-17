/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:10 by aarribas          #+#    #+#             */
/*   Updated: 2022/10/17 15:38:44 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	check_sorted_nb(t_stack *stack_a)
{
	size_t	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->array[i] < stack_a->array[i + 1])
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_global	global;

	if (ac < 2)
		return (1);
	if (stacks_fill(--ac, &av[1], &global.stack_a, &global.stack_b))
		return (1);
	if (check_sorted_nb(&global.stack_a))
	{
		if (global.stack_a.size <= 5)
			start_sort_small(&global.stack_a, &global.stack_b);
		if (global.stack_a.size > 5)
			if (start_sort_big(&global))
				return (1);
	}
	free(global.stack_a.array);
	free(global.stack_b.array);
	return (0);
}
