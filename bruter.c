/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:54:35 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/14 15:22:29 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		equal_tetr(int el, USI f[26][3])
{
	int temp;

	temp = el + 1;
	while (temp < 26 && f[temp][0])
	{
		if (f[temp][0] == f[el][0])
			f[temp][2] = f[el][2];
		++temp;
	}
}

int				ft_bruter(USI f[26][3], char *square, int el, int s)
{
	if (el == 26 || f[el][0] == 0)
		return (1);
	while (1)
	{
		if (ft_insert(f[el], square, s) == -1)
			break ;
		else
			equal_tetr(el, f);
		if (ft_bruter(f, square, el + 1, s) == 1)
			return (1);
		ft_clear(f, square, el, s);
	}
	f[el][2] = NOT_USE;
	return (0);
}
