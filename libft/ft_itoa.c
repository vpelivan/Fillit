/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:09:32 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/01 19:35:30 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_check(int n, int *j, unsigned int *k)
{
	if (n < 0)
	{
		*j = 1;
		if (n == -2147483648)
			*k = 2147483648;
		else
			*k = n * (-1);
	}
}

static int		ft_count_memory(int n)
{
	int	sign;
	int	digit;

	sign = 0;
	digit = 1;
	if (n < 0)
	{
		sign = 1;
		if (n == -2147483648)
			n = -1111111111;
		n *= -1;
	}
	if (n >= 10)
	{
		while (n >= 10)
		{
			n /= 10;
			digit++;
		}
	}
	if (sign == 1)
		return (digit + 1);
	return (digit);
}

char			*ft_itoa(int n)
{
	int				i;
	int				j;
	unsigned int	k;
	char			*str;

	j = 0;
	i = ft_count_memory(n);
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ft_check(n, &j, &k);
	if (n >= 0)
		k = n;
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = k % 10 + 48;
		k /= 10;
		i--;
		if (i == 0 && j == 1)
			break ;
	}
	if (j == 1)
		str[i] = '-';
	return (str);
}
