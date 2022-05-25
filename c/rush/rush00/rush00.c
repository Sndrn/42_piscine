/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:12:33 by santonie          #+#    #+#             */
/*   Updated: 2021/07/11 10:14:49 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.h"

void	middle(int l, int x)
{
	ft_putchar('\n');
	while (l <= x - 1)
	{
		if (l == 0 || l == x - 1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		l++;
	}
}

void	horizontal (int c, int x)
{
	while (c <= x - 1)
	{
		if (c == 0 || c == x - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		c++;
	}
}

void	rush (int x, int y)
{
	int	c;
	int	l;
	int	count;

	c = 0;
	l = 0;
	count = y;
	if (x > 0 && y > 0)
	{
		horizontal(c, x);
	}
	while (count > 0)
	{
		if (count > 2)
		{
			middle(l, x);
		}
		if (count == 2)
		{
			ft_putchar('\n');
			horizontal(c, x);
		}
		count --;
	}
}
 
