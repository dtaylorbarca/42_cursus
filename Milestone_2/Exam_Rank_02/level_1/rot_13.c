/*

Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>

*/

#include <unistd.h>

int	ft_isprintable(unsigned char c)
{
	return (32 <= c && c < 127);
}

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
	int	i = 0;
	unsigned char **uarg = (unsigned char **) argv;

	if (argc == 2)
	{
		while (uarg[1][i])
		{
			if (ft_isprintable(uarg[1][i]))
			{
				if (ft_isupper(uarg[1][i]))
				{
					uarg[1][i] += 13;
					if  (uarg[1][i] > 'Z')
						uarg[1][i] -= 26;
				}
				else if (ft_islower(uarg[1][i]))
				{
					uarg[1][i] += 13;
					if  (uarg[1][i] > 'z')
						uarg[1][i] -= 26;
				}
				write(1, &uarg[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
