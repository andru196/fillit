/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:33:52 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/13 22:41:30 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define USI unsigned short int
# include "libft.h"
# include <fcntl.h>

#include <stdio.h>

int		gnb(USI byte, int n);
int		snb(USI byte, int n, int bit);
void	print_bits(USI c);
USI     ter_transform(char *s);
int     ft_read(int fd, USI figure[26][3]);
int		str_count(char *s);
int		str_position(char *s);
void	ft_sort(USI f[26][3]);
void	ft_sq_clear(USI f[26][3], char *square, int el, int s);
void	ft_clear(USI f[26][3], char *square, int el, int s);
int		ft_get_in(USI f, char *sq, int s, int k);
USI		ft_searcher(USI f[3], char *sq, int s);
int		ft_insert(USI f[3], char *square, int s);
void	ft_swap(USI f[26][3], int el, int i);
int		ft_bruter(USI f[26][3], char *square, int el, int s);
int		ft_side(int figures);
void	ft_print_result(char *square, int side);
int		fillit(USI figure[26][3]);
int		ft_error(int error);
void	inzero(USI f[26][3]);
void	equal_tetr(int el, USI f[26][3]);

#endif
