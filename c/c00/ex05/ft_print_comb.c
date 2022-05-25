/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:03:23 by santonie          #+#    #+#             */
/*   Updated: 2021/07/11 17:45:48 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	{
		if (a != '7' || b != '8' || c != '9')
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = '0' - 1;
	while (x++ < '7')
	{
		y = x;
		while (y++ < '8')
		{
			z = y;
			while (z++ < '9')
			{
				ft_putchar(x, y, z);
			}
		}
	}
}
