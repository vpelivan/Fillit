/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:03:45 by vpelivan          #+#    #+#             */
/*   Updated: 2018/12/31 09:54:34 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**fill_cut_tab(char *str, char **cut, int letter, int limit)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		(cut[i] = ft_memalloc(17)) ? cut[i] : error();
		k = 0;
		while (j <= limit && str[j])
		{
			(str[j] == '#') ? (cut[i][k++] = letter) : 0;
			(str[j] == '.') ? (cut[i][k++] = str[j]) : 0;
			j++;
		}
		i++;
		letter++;
		limit += 21;
	}
	cut[i] = 0;
	return (cut);
}

char		**tetr_cut(char *str, int count)
{
	int		limit;
	int		letter;
	char	**cut;

	letter = 'A';
	limit = 20;
	(cut = (char **)malloc(sizeof(char *) * count + 1)) ? cut : error();
	cut = fill_cut_tab(str, cut, letter, limit);
	return (cut);
}
