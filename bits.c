/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:32:19 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/13 15:16:27 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	gnb(USI byte, int n) /*get n'th bit*/
{
	return ((byte & (1 << (15 - n))) != 0);
}

int snb(USI byte, int n, int bit) /*set n'th bit*/
{
	if ((bit != 0 && bit != 1) || n < 0 || n > 7)
		return (-1);
	else if (bit == 1)
		return (byte | (1 << (7 - n)));
	else
		return (byte & (0xFF - ft_pow(2, 7 - n)));
}

void	print_bits(USI c)
{
	int		i;
	char	c1;
	
	i = 0;
	while (i < 16)
	{
		c1 = gnb(c, i++) + '0';
		write(1, &c1, 1);
	}
	write(1, "\n", 1);
}
