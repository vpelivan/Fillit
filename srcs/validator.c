/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:53:38 by vpelivan          #+#    #+#             */
/*   Updated: 2018/12/31 09:53:42 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				validation_blocks(char *block, int k)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + k < 20 + k)
	{
		if (block[i + k] == '#')
		{
			if ((i + k + 1) < (20 + k) && block[i + k + 1] == '#')
				count++;
			if ((i + k - 1) >= (0 + k) && block[i + k - 1] == '#')
				count++;
			if ((i + k + 5) < (20 + k) && block[i + k + 5] == '#')
				count++;
			if ((i + k - 5) >= (0 + k) && block[i + k - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (count);
	return (0);
}

static int		validation_character(char *block, int k)
{
	int hash;
	int point;
	int line;
	int i;

	i = 0;
	hash = 0;
	point = 0;
	line = 0;
	while (i + k < 20 + k && block[i + k] != '\0')
	{
		if (block[i + k] == '#')
			hash++;
		if (block[i + k] == '.')
			point++;
		if (block[i + k] == '\n')
			line++;
		i++;
	}
	if (hash == 4 && point == 12 && line == 4)
		return (1);
	return (0);
}

int				check_string(char *block)
{
	int i;
	int k;

	i = 0;
	k = i;
	if (!block)
		return (0);
	while (block[i + k] != '\0')
	{
		if (!(validation_blocks(block, k) && validation_character(block, k)))
			return (0);
		i = 19;
		if (block[i + k] == '\n' && block[i + k + 1] == '\0')
			return (1);
		if (block[i + k] == '\n' && block[i + k + 1] == '\n'
			&& (block[i + k + 2] == '.' || block[i + k + 2] == '#'))
			k = 21 + k;
		else
			return (0);
		i = 0;
	}
	return (1);
}
