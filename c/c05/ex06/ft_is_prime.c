/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:49:22 by santonie          #+#    #+#             */
/*   Updated: 2021/07/26 14:31:22 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int	ft_is_prime(int nb)
{
	int	x;

	if (nb < 2)
		return (0);
	x = (nb - 1);
	while (nb % x != 0)
		x--;
	if (x == 1)
		return (1);
	else
		return (0);
}
