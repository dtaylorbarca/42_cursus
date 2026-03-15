/*

Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
 
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
 
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
 
and so on.
 
Case is not changed.
 
If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

*/

#include <unistd.h>

int	ft_isupper(unsigned char c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_islower(unsigned char c)
{
	return ('a' <= c && c <= 'z');
}

int	main(int argc, char **argv)
{
	int	i = -1;
	unsigned char **uarg = (unsigned char **) argv;

	if (argc == 2)
	{
		while (uarg[1][++ i])
		{
			if (ft_isupper(uarg[1][i]))
				uarg[1][i] = 'Z' - uarg[1][i] + 'A';
			else if (ft_islower(uarg[1][i]))
				uarg[1][i] = 'z' - uarg[1][i] + 'a';
			write (1, &uarg[1][i], 1);
		}
	}
	write(1, "\n", 1);
}
