/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:33:52 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/14 15:18:00 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define USI unsigned short int
# define NOT_USE 4044
# include "libft.h"
# include <fcntl.h>

int		gnb(USI byte, int n);
int		ft_read(int fd, USI figure[26][3]);
void	ft_clear(USI f[26][3], char *square, int el, int s);
int		ft_insert(USI f[3], char *square, int s);
int		ft_bruter(USI f[26][3], char *square, int el, int s);
int		fillit(USI figure[26][3]);

#endif
