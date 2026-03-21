/*

Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>

*/

#include <unistd.h>

int	ft_isprintable(unsigned char c)
{
	return (32 <= c && c < 127);
}

int	ft_islower(unsigned char c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_isupper(unsigned char c)
{
	return ('A' <= c && c <= 'Z');
}

int	main(int argc, char **argv)
{
	int	i = 0;
	unsigned char **uarg = (unsigned char **) argv;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (uarg[1][i])
	{
		if (ft_isprintable(uarg[1][i]))
		{
			if (ft_islower(uarg[1][i]))
			{
				uarg[1][i] += 1;
				if (uarg[1][i] > 'z')
					uarg[1][i] -= 26;
			}
			else if (ft_isupper(uarg[1][i]))
			{
				uarg[1][i] += 1;
				if (uarg[1][i] > 'Z')
					uarg[1][i] -= 26;
			}
			write(1, &uarg[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
