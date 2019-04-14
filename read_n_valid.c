/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:16:01 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/04/14 15:40:37 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static USI			ter_transform(char *s)
{
	unsigned short int rez;
	unsigned short int i;
	unsigned short int j;

	i = 15;
	j = 16;
	rez = 0;
	while (j-- && *s != '#')
		s++;
	if ((j % 4) < 2 && *(s + 2) == '#')
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

static int			val_str_position(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s)
	{
		i++;
		if (*s == '#' && j != 3)
		{
			if (*s == '#' && *(s + 1) == '#' && *(s + 4) == '#' && i < 13)
				j += 2;
			else if ((*(s + 1) == '#' && i % 4) || (*(s + 4) == '#' && i < 13)
				|| (i % 4 > 1 && *(s + 2) == '#' && i < 15 &&
				(i % 4 > 2 && *(s + 3) == '#' && i < 14) &&
				(i % 4 > 2 && *(s + 4) == '#' && i < 13)) ||
				(i % 4 > 2 && *(s + 3) == '#' && i < 14 &&
				(i % 4 > 2 && *(s + 4) == '#' && i < 13)))
				j++;
		}
		s++;
	}
	return (j == 3 ? 1 : 0);
}

static int			val_str_count(char *s)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 0;
	k = 0;
	while (*s)
	{
		if (*s == '.')
			j++;
		if (*s == '#')
			i++;
		k++;
		s++;
	}
	return (j == 12 && i == 4 && k == 16 ? 1 : 0);
}

static int			help_read(USI figure[26][3], int *flag,
								char *tmp_line, char *buf)
{
	flag[0] = 0;
	flag[1] += 1;
	flag[2] += 4;
	ft_strcat((char *)tmp_line, (const char *)buf);
	if (flag[2] > (26 * 16))
		return (-1);
	if (flag[1] == 4)
	{
		if (!(val_str_count(tmp_line)) || !(val_str_position(tmp_line)))
			return (-1);
		figure[(flag[2] / 16) - 1][0] = ter_transform((char *)tmp_line);
		figure[(flag[2] / 16) - 1][1] = (flag[2] / 16) - 1 + 'A';
		ft_bzero((void *)tmp_line, 17);
	}
	return (0);
}

int					ft_read(int fd, USI figure[26][3])
{
	int		flag[3];
	char	tmp_line[17];
	char	*buf;

	ft_bzero((void *)flag, 12);
	ft_bzero((void *)tmp_line, 17);
	while (get_next_line(fd, &buf) == 1 || buf)
	{
		if (flag[0] == 2 || flag[1] == 5)
			return (-1);
		if (ft_strlen((char *)buf) == 0)
		{
			flag[0] += 1;
			flag[1] = flag[1] == 4 ? 0 : 1;
		}
		else if (ft_strlen((char *)buf) == 4)
		{
			if (help_read(figure, flag, tmp_line, buf) == -1)
				return (-1);
		}
		else
			return (-1);
		free(buf);
	}
	return (flag[1] == 0 ? 0 : -1);
}
