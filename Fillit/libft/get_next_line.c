/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:16:02 by vpelivan          #+#    #+#             */
/*   Updated: 2018/12/04 14:14:58 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	read_join_free(const int fd, char **str, int *i)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	*i = read(fd, buff, BUFF_SIZE);
	buff[*i] = '\0';
	tmp = *str;
	*str = ft_strjoin(*str, buff);
	free(tmp);
}

static int	buff_copy(char **line, char **str, char **tmp)
{
	**tmp = 0;
	if (!(*line = ft_strdup(*str)))
		return (-1);
	ft_memcpy(*str, *tmp + 1, ft_strlen(*tmp + 1) + 1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			i;
	static char	*str[0];
	char		*tmp;
	char		err[0];

	if (fd < 0 || read(fd, err, 0) < 0)
		return (-1);
	i = 1;
	while (i > 0)
	{
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		if ((tmp = ft_strchr(str[fd], '\n')) != 0)
			return (buff_copy(&(*line), &str[fd], &tmp));
		read_join_free(fd, &str[fd], &i);
	}
	if (i == 0 && ft_strlen(str[fd]))
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_memset(str[fd], 0, ft_strlen(str[fd]));
		i = 1;
	}
	return (i);
}
