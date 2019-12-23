/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:51:08 by vpelivan          #+#    #+#             */
/*   Updated: 2018/12/31 09:41:58 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

char	**paste_in_map(char **map, char *tetr, int x, int y)
{
	int k;
	int i;
	int j;
	int point;

	point = count_points(tetr);
	k = point;
	while (tetr[k])
	{
		i = y + (k / 4) - (point / 4);
		j = x + (k % 4) - (point % 4);
		if (tetr[k] != '.')
			map[i][j] = tetr[k];
		k++;
	}
	return (map);
}

int		resolve(char **cut, char **map, int i, int y)
{
	int x;

	if (!cut[i])
		return (1);
	while (++y < count_line(map))
	{
		x = -1;
		while (++x < count_line(map))
		{
			if (check_map(map, cut[i], x, y) == 0)
			{
				map = paste_in_map(map, cut[i], x, y);
				if (resolve(cut, map, i + 1, -1) == 1)
					return (1);
				else
				{
					if (g_same++ >= 2000000)
						return (0);
					map_out(map, cut[i]);
				}
			}
		}
	}
	return (0);
}

void	solve(int count, char *str)
{
	int		size;
	char	**map;
	char	**cut;

	g_same = 0;
	size = mapsize(count);
	cut = tetr_cut(str, count);
	if (count == 1 && validation_blocks(str, 0) == 8)
		size = 2;
	else if (count == 1 && validation_blocks(str, 0) != 8)
		size++;
	else if (count == 4)
		size = 4;
	map = minmap(size);
	while (resolve(cut, map, 0, -1) == 0)
	{
		size = size + 1;
		free_map(map);
		map = minmap(size);
	}
	ft_print_tab(map);
	free_map(map);
	free_map(cut);
}

int		main(int ac, char **av)
{
	int		fd;
	int		count;
	int		check;
	char	*str;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			error();
		str = read_block(fd);
		close(fd);
		check = check_string(str);
		count = count_block(str);
		if (count == 0 || !str || check == 0)
			error();
		solve(count, str);
		free(str);
	}
	return (0);
}
