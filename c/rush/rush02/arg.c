/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:32:02 by santonie          #+#    #+#             */
/*   Updated: 2021/07/25 20:44:32 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	a_error(void)
{
	ft_putstr("Error\n");
}

int	a_is_num(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
		{
			a_error();
			return (0);
		}
		s++;
	}
	return (1);
}

int	 main(int argc, char **argv)
{
	if (argc < 2)
	{
		a_error();
		return (0);
	}
	else if (argc > 3)
	{
		a_error();
		return (0);
	}
	else if (argc == 2)
	{
		if (a_is_num(argv[1]))
		{
			return (1);
		}
		return (0);
	}
	else if (argc == 3)
	{
		if (a_is_num(argv[2]))
		{
			return (1);
		}
		return (0);
	}
	a_error();
	return (0);
}
