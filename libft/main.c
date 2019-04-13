#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(int argc, char **argv)
{
	printf("%d == %d\n", atoi(argv[1]), ft_atoi(argv[1]));
	return (0);
}