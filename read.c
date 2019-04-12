/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:16:01 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/12 20:19:49 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

USI					ter_transform(char *s)
{
	unsigned short int rez;
	unsigned short int i;
	unsigned short int j;

	i = 15;
	j = 16;
	rez = 0;
	while (j-- && *s != '#')
		s++;
	if  ((j % 4) < 2 && *(s + 2) == '#')
		s -= 2;
	else if ((j % 4) < 3 && ((*(s + 3) == '#') || *(s + 7) == '#')) 
		s -= 1;
	while (*s && i)
	{
		if (*s == '#')
			rez += ft_pow(2, i);
		s++;
		i--;
	}
	return (rez);
}

/*
void				zeroner(int *arr, int f)
{
	if (f == 4)
	{
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 0;
	}
	if (f == 0)
}*/

int					ft_read(int fd, USI figure[26][3])
{
	int		flag_error; // переделать в массив
	int		flag_lines;
	int		flag_file;
	char	temp_line[17];
	char	*buf;

	flag_error = 0; // юзаьб бизиро
	flag_lines = 0;
	flag_file = 0;
	ft_bzero((void *)temp_line, 17);
	while (get_next_line(fd, &buf) == 1 || buf)
	{
		if (flag_error == 2)
			return (-1);
		if (flag_lines == 5)
			return (-1);
		if (ft_strlen((char *)buf) == 0)
		{
			flag_error += 1;
			flag_lines = flag_lines == 4 ? 0 : 1;
		}
		else if (ft_strlen((char *)buf) == 4)
		{
			flag_lines += 1;
			flag_error = 0;
			ft_strcat((char *)temp_line, (const char *)buf);
			flag_file += 4;
			if (flag_file > (26 * 16))
				return (-1);
			if (flag_lines == 4)
				{
					if (!(str_count(temp_line)) || !(str_position(temp_line)))
						return (-1);
					figure[(flag_file/16) - 1][0] = ter_transform((char *)temp_line);
					figure[(flag_file/16) - 1][1] = (flag_file/16) - 1 + 'A';
					ft_bzero((void *)temp_line, 17);
				}
		}
		else
			return (-1);
		free(buf);
	}
	return (flag_lines == 0 ? 0 : -1);
}
