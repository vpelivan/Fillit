/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:06:14 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/08 14:48:28 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_len(char const *s, char c, size_t i)
{
	size_t len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char		**ft_split(char const *s, char c, size_t i, size_t j)
{
	size_t	l;
	size_t	k;
	char	**str;

	l = 0;
	str = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (l < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(str[j] = (char*)malloc(sizeof(char) * (ft_w_len(s, c, i) + 1))))
			return (NULL);
		k = 0;
		while (s[i] != c && s[i])
		{
			str[j][k++] = s[i];
			i++;
		}
		str[j++][k] = '\0';
		l++;
	}
	str[j] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t i;
	size_t j;

	if (!s || (!c && c != '\0'))
		return (NULL);
	i = 0;
	j = 0;
	return (ft_split(s, c, i, j));
}
