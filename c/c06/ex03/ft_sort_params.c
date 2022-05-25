/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santonie <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:32:25 by santonie          #+#    #+#             */
/*   Updated: 2021/07/29 13:21:35 by santonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
	write (1, &c, 1);
}

/*char *ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		ft_putchar(str[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	int		max;
	int		i;
//	int		j;
	char	*tmp;

	max = 0;
	i = 1;
//	j = 0;
	while (i < argc)
	{
		max = ft_strcmp(argv[i], argv[i + 1]);
		if (max > 0)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
		}
		i++;
	}
	printf("%s\n", argv[i]);
//	printf("%s\n", ft_putstr(argv[i+1]));
    return (0);
}
    
