/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:22:16 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/13 15:15:38 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	ft_tochechka(char *sq, int side)
{
	int i;

	i = -1;
	while (++i < side * side)
		*sq++ = '.';
}

int		fillit(USI figure[26][3])
{
    int		side;
    char	*square;
	int 	i;

	side = 0;
	while (figure[side][0])
		++side;
	if ((side = ft_side(side)) == -1)
		return (-1);
	while (1)
	{
		if (!(square = ft_strnew(side * side)))
			return (-1);
		ft_tochechka(square, side);
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

int ft_error(int error)
{
	if (error == 0)
		ft_putstr("error\n");
	else if (error == 1)
		ft_putstr("usage: ./fillit file\n");
	return (-1);
}

void	inzero(USI f[26][3])
{
	int i;

	i = 0;
	while (i < 26)
	{
		f[i][0] = 0;
		f[i][1] = 0;
		f[i][2] = 4044;
		i++;
	}
}

int main(int argc, char **argv)
{
	int		fd;
	USI		figure[26][3];
	int		i;

	if (argc != 2)
		return (ft_error(1));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(0));
	i = 0;
	inzero(figure);
	if (ft_read(fd, figure) == -1)
		return (ft_error(0));
	if (fillit(figure) == -1)
		return (ft_error(0));
	return (0);
}
