/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:16:01 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/02/11 15:16:04 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

USI	ter_transform(char *s)
{
	USI rez;
	USI i;
	USI j;

	i = 15;
	j = 16;
	while (j-- && *s != '#')
		s++;
	printf("%d\n", j);
	if  ((j % 4) < 2 && *(s + 2) == '#')
		s -= 2;
	else if ((j % 4) < 3 && *(s + 3) == '#')
		s -= 1;
	while (*s && i)
	{
		if (*s == '#')
			rez += ft_power(2, i);
		s++;
		i--;
	}
	return (rez);
}

USI *error_cleaner(char *s, char *s2, USI *a)
{
	if (a)
		free(a);
	if (s)
		free(s);
	if (s2)
		free(s2);
	return (NULL);
}

USI *reader(char *file_name)
{
	USI		*rez;
	char	*str;
	char	*tetr;
	int 	fd;
	int		i;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return NULL;
	if (!(rez = ft_memmalloc(sizeof(USI) * 25)))
		return rez;
	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		if (!(tetr = ft_strjoin(tetr, str)))
			return error_cleaner(tetr, str, rez);
		if (ft_strlen(tetr > 15))
		{
			if (str_count(tetr) && str_position(tetr))
				rez[i++] = ter_transform(tetr);
			else
				return error_cleaner(tetr, str, rez);
			free(tetr);
			tetr = NULL;
		}
	}
	return (rez);
}
