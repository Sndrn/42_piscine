/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:09:13 by santonie          #+#    #+#             */
/*   Updated: 2021/07/15 20:47:04 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*x;

	x = str;
	while (*x != '\0')
	{
		if (*x >= 97 && *x <= 122)
		{
			*x -= 32;
		}	
		x++;
	}
	return (str);
}
