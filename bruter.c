/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:54:35 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/13 22:59:34 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_bruter(USI f[26][3], char *square, int el, int s)
{
	if (el == 26 || f[el][0] == 0)
		return (1);
	while (1)
	{
		if (ft_insert(f[el], square, s) == -1)
			break;
		else
			equal_tetr(el, f);
		if (ft_bruter(f, square, el + 1, s) == 1)
			return (1);
		ft_clear(f, square, el, s);
	}
	f[el][2] = 4044;
	return (0);
}

void		equal_tetr(int el, USI f[26][3])
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

void	ft_swap(USI f[26][3], int el, int i)
{
	USI	temp[3];

	temp[0] = f[el][0];
	temp[1] = f[el][1];
	temp[2] = f[el][2];
	f[el][0] = f[i][0];
	f[el][1] = f[i][1];
	f[el][2] = f[i][2];
	f[i][0] = temp[0];
	f[i][1] = temp[1];
	f[i][2] = temp[2];
}

int		ft_side(int figures)
{
	int side;

	if (figures == 0)
		return (-1);
	side = 2;
	while ((figures * 4) > side * side)
		++side;
	return (side);
}

void	ft_print_result(char *square, int side)
{
	int i;
	int j;

	i = 0;
	while (i < side * side)
	{
		j = 0;
		while (++j <= side)
			ft_putchar(square[i++]);
		ft_putchar('\n');
	}
}
