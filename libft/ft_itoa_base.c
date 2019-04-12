/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:11:00 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/02/22 19:35:38 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	int							counter;
	unsigned long long int		copy;
	char						*result;

	result = NULL;
	if (base == 10)
		result = ft_itoa(value);
	else if (base >= 2 && base <= 16)
	{
		copy = value < 0 ? -(long long int)value : value;
		value = value < 0 ? -(long long int)value : value;
		counter = 1;
		while ((value /= base))
			++counter;
		if (!(result = ft_strnew(counter)))
			return (NULL);
		result[0] = copy == 0 ? '0' : result[0];
		while (copy)
		{
			result[--counter] = ft_isdigit(copy % base + '0') ?
							copy % base + '0' : copy % base + 'A' - 10;
			copy /= base;
		}
	}
	return (result);
}
