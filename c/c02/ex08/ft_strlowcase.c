/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:14:54 by santonie          #+#    #+#             */
/*   Updated: 2021/07/15 20:48:19 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*x;

	x = str;
	while (*x != '\0')
	{
		if (*x >= 65 && *x <= 90)
		{
			*x += 32;
		}
		x++;
	}
	return (str);
}