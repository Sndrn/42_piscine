/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:35:42 by santonie          #+#    #+#             */
/*   Updated: 2021/07/27 12:53:10 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*sjoin;
	int		i;

	sjoin = malloc(sizeof(strs));
	i = 0;
	while (i < size)
	{
		ft_strcat(sjoin, strs[i]);
		if (i < size - 1)
			ft_strcat(sjoin, sep);
		i++;
	}
	return (sjoin);
}
