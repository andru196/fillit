/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:30:03 by ycorrupt          #+#    #+#             */
/*   Updated: 2018/12/27 14:40:21 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if ((!s1 ^ !s2) || ((s1 && s2) && ft_strcmp(s1, s2) != 0))
		return (0);
	else
		return (1);
}
