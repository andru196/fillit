/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:54:35 by ycorrupt          #+#    #+#             */
/*   Updated: 2019/04/12 20:58:31 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_figs(char *s, USI f[26][3])
{
	int i;

	i = 0;
	printf("%s\nfigs:\t", s);
	while (f[i][0])
		printf("%d\t", f[i++][0]);
	printf("\nwords:\t");
	i = 0;
	while (f[i][0])
		printf("%c\t", f[i++][1]);
	printf("\nposes:\t");
	i = 0;
	while (f[i][0])
		printf("%d\t", f[i++][2]);
	printf("\n-----------------------------------\n");
}

void	ft_sort(USI f[26][3])
{
	int	i;
	int fl;

	i = 0;

	fl = 1;
	while (fl)
	{	
		fl = 0;
		i = 0;
		while (i < 25 && f[i + 1][0])
		{
			if (f[i][1] > f[i + 1][1])
			{
				ft_swap(f, i, i + 1);
				fl = 1;
			}
			i++;
		}
	}
}

void	ft_sq_clear(USI f[26][3], char *square, int el, int s)
{
	int	i;
	int	j;

	i = el;
	while (i < 26 && f[i][0])
	{
		if (f[i][2] != 4044 && f[i][2] != 4040)
		{
			j = 0;
			while (j < 16)
			{
				if (gnb(f[i][0], j))
					square[f[i][2] + (j / 4 * s) + j % 4] = '.';
				j++;
			}
			f[i][2] = el == i ? f[i][2] : 4044;
		}
		i++;
	}
}

void	ft_clear(USI f[26][3], char *square, int el, int s)
{
	USI	copy[26][3];
	int	i;
	int j;
	int k;

	inzero(copy);
	i = el;
	ft_sq_clear(f, square, el, s);
	while (f[i][0])
	{
		copy[i - el][0] = f[i][0];
		copy[i - el][1] = f[i][1];
		i++;
	}
	i = el;
	ft_sort(copy);
	j = 0;
	k = 0;
	while (el + 'A' > copy[j][1])
		j++;
	while (i < 26 && f[i][0])
	{
		if (i + 'A' == copy[j][1])
		{
			f[i][1] = copy[j][1];
			f[i][0] = copy[j++][0];
		}
		else
		{
			f[i][1] = copy[k][1];
			f[i][0] = copy[k++][0];
		}
		i++;
	}

}

int		ft_get_in(USI f, char *sq, int s, int k) // Сделать модификацию для кривых фигур
{
	int i;
	int j;
	int result_flag;

	i = 0;
	result_flag = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (f & (1 << (15 - i * 4 - j)))
			{
				if (sq[k + i * s + j] == '.' && (k % s + j < s) && (((k + i * s) / s) < s))
					result_flag += 1;
				else
					return (0);
			if (result_flag == 4)
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

USI		ft_searcher(USI f[3], char *sq, int s)
{
	int i;

	i = f[2] == 4044 ? 0 : f[2] + 1;
	while (i < s * s)
	{
		if (sq[i] == '.')
		{
			if (i != 0 && sq[i - 1] != '.')
			{
				if (f[0] < (1 << 14) && i - 2 != f[2])
				{
					if (ft_get_in(f[0], sq, s, i - 2))
						return (i - 2);
				}
				if (f[0] < (1 << 15) && i - 1 != f[2])
				{
					if (ft_get_in(f[0], sq, s, i - 1))
						return (i - 1);
				}
			}
			if (ft_get_in(f[0], sq, s, i))
				return (i);
		}
			
		i++;
	}
	return (4040);
}

int		ft_insert(USI f[3], char *square, int s)
{
	USI pos;
	int i;
	int j;

	if ((pos = ft_searcher(f, square, s)) == 4040)
		return (-1);
	f[2] = (USI)pos;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (gnb(f[0], j + i * 4))
				square[pos + j + i * s] = f[1];
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_swap(USI f[26][3], int el, int i)
{
	USI	temp[3];

	temp[0] = f[el][0];
	temp[1] = f[el][1];
	temp[2] = f[el][2];
	f[el][0] = f[i][0];
	f[el][1] = f[i][1];
	f[el][2] = f[i][2];
	f[i][0] = temp[0];
	f[i][1] = temp[1];
	f[i][2] = temp[2];
}

int		ft_bruter(USI f[26][3], char *square, int el, int s)
{
	int i;

	if (el == 26 || f[el][0] == 0)
		return (1);
	i = el;
	while (f[i][0])
	{
		ft_swap(f, el, i);
		while (f[el][2] != 4040)
		{
			if (ft_insert(f[el], square, s) == -1)
				break;
			if (ft_bruter(f, square, el + 1, s) == 1)
				return (1);
			//write(1, "1\n", 2);
			//ft_print_result(square, s);
			ft_clear(f, square, el, s);
			//write(1, "2\n", 2);
			//ft_print_result(square, s);
		}
		f[el][2] = 4044;
		i++;
	}
	return (0);
}

int		ft_side(int figures)
{
	int side;

	if (figures == 0)
		return (-1);
	side = 2;
	while ((figures * 4) > side * side)
		++side;
	return (side);
}

void	ft_print_result(char *square, int side)
{
	int i;
	int j;

	i = 0;
	while (i < side * side)
	{
		j = 0;
		while (++j <= side)
			ft_putchar(square[i++]);
		ft_putchar('\n');
	}
}

void	ft_tochechka(char *sq, int side)
{
	int i;

	i = -1;
	while (++i < side * side)
		*sq++ = '.';
}

int		fillit(USI figure[26][3])
{
    int		side;
    char	*square;
	int 	i;

	side = 0;
	while (figure[side][0])
		++side;
	if ((side = ft_side(side)) == -1)
		return (-1);
	while (1)
	{
		if (!(square = ft_strnew(side * side)))
			return (-1);
		ft_tochechka(square, side);
		if (ft_bruter(figure, square, 0, side) == 1)
			break ;
		ft_memdel((void **)&square);
		++side;
		i = 0;
		while (figure[i][0])
		{
			figure[i][2] = 4044;
			i++;
		}
	}
	ft_print_result(square, side);
	ft_memdel((void **)&square);
	return (1);
}
