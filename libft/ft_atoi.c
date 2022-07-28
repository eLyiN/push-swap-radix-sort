/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:50:32 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/21 12:17:29 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_atoi has to be modified to this proyect, the reason was to check if the nb
** is in range from int and we could return true or false while we're editing
** our nb */

int	ft_atoi(const char *str, int *nb)
{
	int		i;
	int		signo;
	long	nbr;

	i = 0;
	signo = 1;
	nbr = 0;
	if (str[i] == '-')
	{
		if (str[i] == '-')
			signo *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		return (1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || nbr * signo > 2147483647 || nbr * signo < -2147483648)
		return (1);
	*nb = (int)nbr * signo;
	return (0);
}
