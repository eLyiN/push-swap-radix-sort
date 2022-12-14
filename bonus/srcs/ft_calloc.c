/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:48:54 by aarribas          #+#    #+#             */
/*   Updated: 2022/07/29 23:49:48 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems == __SIZE_MAX__ && size > 1)
		return (NULL);
	if (size == __SIZE_MAX__ && nitems > 1)
		return (NULL);
	ptr = malloc(nitems * size);
	if (ptr == NULL)
	{
		return (ptr);
	}
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
