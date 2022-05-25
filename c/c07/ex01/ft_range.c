/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:54:26 by santonie          #+#    #+#             */
/*   Updated: 2021/07/26 13:31:55 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int				*tab;
	unsigned int	dif;
	unsigned int	i;	

	i = 0;
	if (min >= max)
		return (NULL);
	dif = (unsigned int)(max - min);
	tab = malloc(dif * sizeof(int));
	if (!tab)
		return (NULL);
	while (i < dif)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
