/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:13:38 by vpelivan          #+#    #+#             */
/*   Updated: 2018/12/31 09:17:17 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

int		g_same;

void	error(void);
char	*read_block(int fd);
int		check_string(char *block);
char	**tetr_cut(char *str, int count);
int		mapsize(int blocks);
void	free_map(char **map);
int		count_points(char *tetr);
int		check_map(char **map, char *tetr, int x, int y);
char	**paste_in_map(char **map, char *tetr, int x, int y);
char	**map_out(char **map, char *tetr);
int		resolve(char **cut, char **map, int i, int y);
int		validation_blocks(char *block, int k);
void	solve(int nb, char *s);
int		count_block(char *str);
char	**minmap(int size);
int		count_line(char **tab);

#endif
