/*

Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/

#include <unistd.h>

int	ft_isprintable(char c)
{
	return (32 < c && c < 127);
}

int	ft_islower(char c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_isupper(char c)
{
	return ('A' <= c && c <= 'Z');
}

int	main(int argc, char **argv)
{
	int	index;
	int	repeat;

	index = 0;
	if (argc == 2)
	{
		while (argv[1][index])
		{
			if (ft_isprintable(argv[1][index]))
			{
				if (ft_islower(argv[1][index]))
					repeat = argv[1][index] - 'a' + 1;
				else if (ft_isupper(argv[1][index]))
					repeat = argv[1][index] - 'A' + 1;
				else
					repeat = 1;
				while (repeat-- > 0)
					write(1, &argv[1][index], 1);
			}
			index ++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
