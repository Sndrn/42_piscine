/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:57:54 by santonie          #+#    #+#             */
/*   Updated: 2021/07/27 14:05:15 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	if (*to_find == '\0')
		return (str);
	a = 0;
	while (str[a] != '\0')
	{
		b = 0;
		while (to_find[b] == str[a + b])
		{
			if (to_find[b + 1] == '\0')
			{
				return (str + a);
			}
			b++;
		}
		a++;
	}
	return (0);
}
