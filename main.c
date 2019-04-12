/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:22:16 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/12 20:23:07 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
