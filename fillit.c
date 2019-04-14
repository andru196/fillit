
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:54:40 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/14 15:37:19 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_print_result(char *square, int side)
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

static int	ft_side(int figures)
{
	int side;

	if (figures == 0)
		return (-1);
	side = 2;
	while ((figures * 4) > side * side)
		++side;
	return (side);
}

int			fillit(USI figure[26][3])
{
	int		side;
	char	*square;
	int		i;

	side = 0;
	while (figure[side][0])
		++side;
	if ((side = ft_side(side)) == -1)
		return (-1);
	while (1)
	{
		if (!(square = ft_strnew(side * side)))
			return (-1);
		ft_memset((void *)square, '.', side * side);
		if (ft_bruter(figure, square, 0, side) == 1)
			break ;
		ft_memdel((void **)&square);
		++side;
		i = 0;
		while (figure[i][0])
			figure[i++][2] = 4044;
	}
	ft_print_result(square, side);
	ft_memdel((void **)&square);
	return (1);
}
