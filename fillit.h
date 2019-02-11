/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:33:52 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/02/09 14:35:04 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define USI unsigned short int
# include "get_next_line.h"
# include <fcntl.h>

int		gnb(unsigned char byte, int n);
int		snb(unsigned char byte, int n, int bit);
void	print_bits(unsigned char c);
USI		*reader(char *file_name);
int		str_count(char *s);
int		str_position(char *s);

#endif
