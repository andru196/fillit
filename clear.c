/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:49:56 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/13 23:05:14 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_sort(USI f[26][3])
{
	int	i;
	int fl;

	i = 0;
	fl = 1;
	while (fl)
	{	
		fl = 0;
		i = 0;
		while (i < 25 && f[i + 1][0])
		{
			if (f[i][1] > f[i + 1][1])
			{
				ft_swap(f, i, i + 1);
				fl = 1;
			}
			i++;
		}
	}
}

void	ft_sq_clear(USI f[26][3], char *square, int el, int s)
{
	int	i;
	int	j;
	int k;

	i = el;
	while (i < 26 && f[i][0])
	{
		if (f[i][2] != 4044)
		{
			k = 0;
			j = 0;
			while (j < 16)
			{
				if (gnb(f[i][0], j))
				{
					if (square[f[i][2] + (j / 4 * s) + j % 4] != f[i][1])
						break;
					k++;
					square[f[i][2] + (j / 4 * s) + j % 4] = '.';
					if (k == 4)
						break;
				}
				j++;
			}
			f[i][2] = el == i ? f[i][2] : 4044;
		}
		i++;
	}
}

void	ft_clear(USI f[26][3], char *square, int el, int s)
{
	USI	copy[26][3];
	int	i;
	int j;
	int k;

	inzero(copy);
	i = el;
	ft_sq_clear(f, square, el, s);
	while (f[i][0])
	{
		copy[i - el][0] = f[i][0];
		copy[i - el][1] = f[i][1];
		i++;
	}
	i = el;
	ft_sort(copy);
	j = 0;
	k = 0;
	while (el + 'A' > copy[j][1])
		j++;
	while (i < 26 && f[i][0])
	{
		if (i + 'A' == copy[j][1])
		{
			f[i][1] = copy[j][1];
			f[i][0] = copy[j++][0];
		}
		else
		{
			f[i][1] = copy[k][1];
			f[i][0] = copy[k++][0];
		}
		i++;
	}
}
