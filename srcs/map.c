/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:02:47 by vpelivan          #+#    #+#             */
/*   Updated: 2018/12/31 09:54:16 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**map_out(char **map, char *tetr)
{
	int		i;
	int		j;
	char	tetr2;

	i = 0;
	tetr2 = tetr[count_points(tetr)];
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == tetr2)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		check_map(char **map, char *tetr, int x, int y)
{
	int point;
	int size;
	int i;
	int j;
	int k;

	size = count_line(map);
	point = count_points(tetr);
	k = point;
	while (tetr[k])
	{
		i = (y + (k / 4) - (point / 4));
		j = (x + (k % 4) - (point % 4));
		if (tetr[k] != '.')
		{
			if (i >= size || j >= size || map[i][j] != '.')
				return (1);
		}
		k++;
	}
	return (0);
}

char	**minmap(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * size + 1);
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}

void	free_map(char **map)
{
	int i;
	int j;

	j = 0;
	i = count_line(map);
	while (j < i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

int		mapsize(int blocks)
{
	int size;
	int i;

	if (blocks == 1)
		return (2);
	i = 0;
	size = blocks * 4;
	while (size >= (i * i))
		i++;
	return (i);
}
