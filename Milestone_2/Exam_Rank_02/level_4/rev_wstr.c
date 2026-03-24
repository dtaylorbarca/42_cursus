/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	len;
	int	index;
	int	holder;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		while (len > 0)
		{
			index = len - 1;
			while (argv[1][index] != ' ' && index >= 0)
				index --;
			holder = index;
			while (argv[1][++ index] != ' ' && index <= len && argv[1][index])
				write(1, &argv[1][index], 1);
			len -= index - holder;
			if (len > 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
