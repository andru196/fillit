/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:22:16 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/14 15:41:03 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_error(int error)
{
	if (error == 0)
		ft_putstr("usage: ./fillit file\n");
	else if (error == 1)
		ft_putstr("error\n");
	return (-1);
}

static void		inzero(USI figure[26][3])
{
	int		i;

	i = 0;
	while (i < 26)
	{
		figure[i][0] = 0;
		figure[i][1] = 0;
		figure[i][2] = NOT_USE;
		i++;
	}
}

int				main(int argc, char **argv)
{
	int		fd;
	USI		figure[26][3];

	if (argc != 2)
		return (ft_error(0));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(1));
	inzero(figure);
	if (ft_read(fd, figure) == -1)
		return (ft_error(1));
	if (fillit(figure) == -1)
		return (ft_error(1));
	return (0);
}
