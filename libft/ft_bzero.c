/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:04:02 by ycorrupt          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:52 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *str;

	if (n)
	{
		str = (char *)s;
		while (n)
		{
			*str = 0;
			++str;
			--n;
		}
	}
}
