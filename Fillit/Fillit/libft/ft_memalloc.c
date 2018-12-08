/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:35:42 by vpelivan          #+#    #+#             */
/*   Updated: 2018/10/31 16:17:25 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(size);
	if (!s)
		return (0);
	while (size >= i)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
