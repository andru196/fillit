/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:49:56 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/14 15:43:43 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_clear(USI f[26][3], char *square, int el, int s)
{
	int	i;
	int	j;

	i = el - 1;
	while (++i < 26 && f[i][0])
	{
		if (f[i][2] != NOT_USE)
		{
			j = -1;
			while (++j < 16)
			{
				if (gnb(f[i][0], j))
				{
					if (square[f[i][2] + (j / 4 * s) + j % 4] != f[i][1])
						break ;
					square[f[i][2] + (j / 4 * s) + j % 4] = '.';
				}
			}
			f[i][2] = el == i ? f[i][2] : NOT_USE;
		}
	}
}
