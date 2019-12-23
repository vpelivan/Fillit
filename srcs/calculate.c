/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:17:13 by vpelivan          #+#    #+#             */
/*   Updated: 2018/12/31 09:53:15 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_block(int fd)
{
	int		file;
	char	c;
	char	*str;
	int		i;

	i = 0;
	if ((file = read(fd, &c, 1)) < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * 545);
	while (file != '\0')
	{
		str[i] = c;
		i++;
		file = read(fd, &c, 1);
	}
	str[i] = '\0';
	return (str);
}

int		count_block(char *str)
{
	int		count;
	char	*p;

	p = str;
	count = 0;
	while (*p != '\0')
	{
		if (*p == '#')
			count++;
		p++;
	}
	count = count / 4;
	if (count > 26)
		error();
	return (count);
}

int		count_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		count_points(char *tetr)
{
	int i;

	i = 0;
	while (tetr[i] == '.')
		i++;
	return (i);
}
