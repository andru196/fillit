/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:11:08 by ycorrupt          #+#    #+#             */
/*   Updated: 2018/12/16 21:19:39 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *p_s1;

	p_s1 = s1;
	while (*s1)
		++s1;
	while (*s2 && n--)
		*s1++ = *s2++;
	*s1 = '\0';
	return (p_s1);
}
