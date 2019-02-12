/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:32:19 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/02/11 16:32:20 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	gnb(unsigned char byte, int n) /*get n'th bit*/
{
	int i;

	if (n < 0 || n > 7)
		return (-1);
	i = 1 << (7 - n);
	return ((byte & i) > 0);
}

int snb(unsigned char byte, int n, int bit) /*set n'th bit*/
{
	if ((bit != 0 && bit != 1) || n < 0 || n > 7)
		return (-1);
	else if (bit == 1)
		return (byte | (1 << (7 - n)));
	else
		return (byte & (0xFF - ft_power(2, 7 - n)));
}

void	print_bits(unsigned char c)
{
	int		i;
	char	c1;
	
	i = 0;
	while (i < 8)
	{
		c1 = gnb(c, i++) + '0';
		write(1, &c1, 1);
	}
	write(1, "\n", 1);
}
