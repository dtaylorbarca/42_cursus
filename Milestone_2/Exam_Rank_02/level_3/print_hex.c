/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

void	print_hex(int num)
{
	char	*base = "0123456789abcdef";
	if (num > 15)
		print_hex(num / 16);
	write(1, &base[num % 16], 1);
}

int	main(int argc, char **argv)
{
	int	result = 0;
	int	i = -1;
	if (argc == 2)
	{
		while (argv[1][++ i])
			result = result * 10 + (argv[1][i] - '0');
		print_hex(result);
	}
	write(1, "\n", 1);
	return (0);
}
