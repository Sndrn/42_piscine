/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joferrei <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:39:41 by joferrei          #+#    #+#             */
/*   Updated: 2021/07/25 19:33:21 by joferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void	ft_putchar(char c);
void	ft_putstr(char *s);
void	d_error(void);
void	skip_spaces(char **str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_read_file(void);

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	d_error(void)
{
	ft_putstr("Dict Error\n");
}

void	skip_spaces(char **str)
{
	while (**str == ' ') //TODO /r /t etc aussi ?
	{
		(*str)++;
	}
}

int	is_num(char	*s)
{
	int i;

	i = 0;
	if (*s >= '0' && *s <= '9')
		return (1);
	else
		return (0);
}

int	is_printable(char *s)
{
	if (*s >= ' ' && *s <= '~')
		return (1);
	else
		return (0);
}

int	get_num(char **s, t_dico *dico)//TODO put in struct
{
	int		i;

	skip_spaces(s);
	i = 0;
	while (is_num(*s + i))
	{	
		i++;
	}
	dico->nbr = (char *)malloc((i + 1) * sizeof(char));
	if (nb == NULL)
		return (-1);
	i = 0;
	while (is_num(*s))
	{
		dico->nbr[i] = **s;
		(*s)++;
		i++;
	}
	dico->nbr[i] = '\0';
	//printf("\nINDICE = %s", nb);
	return (i);
}

int	get_printable(char **s, t_dico *dico) //TODO put in struct
{
	int		i;
	
	skip_spaces(s);
	i = 0;
	while (is_printable(*s + i))
	{
		i++;
	}
	dico->trad = (char *)malloc((i + 1) * sizeof(char));
	if (trad == NULL)
		return (-1);
	i = 0;
	while (is_printable(*s))
	{
		dico->trad[i] = **s;
		(*s)++;
		i++;
	}
	dico->trad[i] = '\0';
	//printf("\nTRADUCTION = %s\n", trad);
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

int	fstrlen(char *s)
{
	int	c;

	c = 0;
	while(*s)
	{
		c++;
		s++;
	}
	return (c);
}

char	*fstrdup(char *s)
{
	char	*s1;
	int		len;
	
	len = fstrlen(s);
	s1 = (char *)malloc(sizeof(char) * len);
	if (s1 == NULL)
		return (NULL);
	s1 = ft_strcpy(s1, s);
	return (s1);
}

char	*ft_read_file(void)
{
	int		fd;
	int		rd_nb;
 	char	*buf;
	char	*str_file;

	fd = open("test.dict.rtf", O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = malloc(sizeof(char) * 4096);
	if (buf == NULL)
		return (NULL);
	rd_nb = read(fd, (buf), 4095);
	buf[rd_nb + 1] = '\0';
	str_file = fstrdup(buf);
	free(buf);
	close(fd);
	return (str_file);
}

int	skip_p(char **s)
{
	skip_spaces(s);
	if (**s == ':')
	{
		(*s)++;
		return (1);
	}
	return (0);
}

int	fcount_lines(char *s)
{
	int c;

	c = 0;
	while (*s)
	{
		if (get_num(&s) && skip_p(&s) && get_printable(&s) && (*s == '\n' || *s == '\0'))
		{
			c++;
		}
		s++;
	}
	return (c);
}

int	get_values(t_dico **dico, char *s)
{
	while (*s)
	{
		if (get_num(&s) && skip_p(&s) && get_printable(&s) && (*s == '\n' || *s == '\0'))
		{

		}
		s++;
	}
}

int	main(void)
{
	char	*str_file;
	t_dico	*dico;
	if (ft_read_file())
	{
		int		nb_line;
		//char	*line;

		str_file = ft_read_file();
		//printf("\n%s\n", str_file); TODO delete

		if (nb_line == 0)
		{
			printf("\nerror1\n");//TODO delete
			d_error();
			return (0);
		}
		nb_line = fcount_lines(str_file);
		dico = (t_dico *)malloc((nb_line + 1) * sizeof(t_dico));
		if (dico == NULL)
			return (0);
		printf("\n%s\nnb_line %d", str_file, nb_line); //TODO delete
	}
	else
	{
		printf("\nerror2\n");//TODO delete
		d_error();
		str_file = 0;
		//TODO fermer le programme
	}
	return (0);
}
