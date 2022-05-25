/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:28:43 by santonie          #+#    #+#             */
/*   Updated: 2021/07/27 12:52:07 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	dif;
	int	i;

	if (min >= max)
	{
		range = ((void *)0);
		return (0);
	}
	i = 0;
	dif = max - min;
	*range = malloc (dif * sizeof(int));
	if (!*range)
		return (-1);
	while (i < dif)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (dif);
}
