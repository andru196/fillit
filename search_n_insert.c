/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_n_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:47:07 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/14 15:27:55 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_get_in(USI f, char *sq, int s, int k)
{
	int i;
	int j;
	int result_flag;

	i = -1;
	result_flag = 0;
	while (++i <= 3)
	{
		j = -1;
		while (++j <= 3)
		{
			if (f & (1 << (15 - i * 4 - j)))
			{
				if (sq[k + i * s + j] == '.' && (k % s + j < s) &&
											(((k + i * s) / s) < s))
					result_flag += 1;
				else
					return (0);
				if (result_flag == 4)
					return (1);
			}
		}
	}
	return (0);
}

static USI	ft_searcher(USI f[3], char *sq, int s)
{
	int i;
	USI fig;

	fig = f[0];
	i = f[2] == NOT_USE ? 0 : f[2] + 1;
	while (i < s * s)
	{
		if (sq[i] == '.')
		{
			if (i != 0 && sq[i - 1] != '.')
			{
				if (fig < (1 << 14) && (i - 2 > f[2] || f[2] == NOT_USE))
					if (ft_get_in(fig, sq, s, i - 2))
						return (i - 2);
				if (fig < (1 << 15) && i - 1 != f[2])
					if (ft_get_in(fig, sq, s, i - 1))
						return (i - 1);
			}
			if (ft_get_in(fig, sq, s, i))
				return (i);
		}
		i++;
	}
	return (NOT_USE);
}

int			gnb(USI byte, int n)
{
	return ((byte & (1 << (15 - n))) != 0);
}

int			ft_insert(USI f[3], char *square, int s)
{
	USI pos;
	int i;
	int j;
	USI fig;

	if ((pos = ft_searcher(f, square, s)) == NOT_USE)
		return (-1);
	f[2] = (USI)pos;
	i = 0;
	fig = f[0];
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (gnb(fig, j + i * 4))
				square[pos + j + i * s] = f[1];
			j++;
		}
		i++;
	}
	return (1);
}
