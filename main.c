/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:22:16 by sfalia-f          #+#    #+#             */
/*   Updated: 2019/02/11 17:26:02 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	USI *arr;

	if (argc == 2)
	{
		arr = reader(argv[1]);
		for (int i = 0; i < 25; i++)
			print_bits(arr[i]);
	}
	return(0);
}
