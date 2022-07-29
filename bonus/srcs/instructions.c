/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:57:48 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/29 23:56:12 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	read_instructions(t_global *main, char *buff)
{
	static char	*mybuffer;
	char		*temp;
	int			size_read;

	size_read = 1;
	while (size_read != 0)
	{
		size_read = read(STDIN_FILENO, buff, 2);
		if (size_read == -1)
		{
			free(buff);
			return (1);
		}
		buff[size_read] = '\0';
		temp = mybuffer;
		if (!temp)
			temp = ft_calloc(1, sizeof(char));
		mybuffer = ft_strjoin(temp, buff);
		free(temp);
	}
	free(buff);
	main->checker.inst_size = count_instr(mybuffer, '\n');
	main->checker.inst = ft_split(mybuffer, '\n');
	free(mybuffer);
	return (0);
}

int	process_instr(t_global *main, char *instruction)
{
	if (!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "ss"))
		swap_sa(&main->stack_a);
	else if (!ft_strcmp(instruction, "sb") || !ft_strcmp(instruction, "ss"))
		swap_sb(&main->stack_b);
	else if (!ft_strcmp(instruction, "pa"))
		swap_pa(&main->stack_a, &main->stack_b);
	else if (!ft_strcmp(instruction, "pb"))
		swap_pb(&main->stack_b, &main->stack_a);
	else if (!ft_strcmp(instruction, "ra") || !ft_strcmp(instruction, "rr"))
		swap_ra(&main->stack_a);
	else if (!ft_strcmp(instruction, "rb") || !ft_strcmp(instruction, "rr"))
		swap_rb(&main->stack_b);
	else if (!ft_strcmp(instruction, "rra") || !ft_strcmp(instruction, "rrr"))
		swap_rra(&main->stack_a);
	else if (!ft_strcmp(instruction, "rrb") || !ft_strcmp(instruction, "rrr"))
		swap_rrb(&main->stack_b);
	else
		return (1);
	return (0);
}

int	run_program(t_global *main)
{
	size_t	i;

	i = 0;
	while (main->checker.inst_size > 0)
	{
		if (process_instr(main, main->checker.inst[i]))
		{
			freedom(main);
			write(STDERR_FILENO, "Error\n", 6);
			return (1);
		}
		i++;
		main->checker.inst_size--;
	}
	return (0);
}
