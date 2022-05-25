/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:49:44 by santonie          #+#    #+#             */
/*   Updated: 2021/07/21 12:36:32 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	racine;

	racine = 1;
	while ((racine * racine) < nb && racine < 46341)
	{
		racine++;
	}
	if ((racine * racine) != nb)
	{
		return (0);
	}
	return (racine);
}
