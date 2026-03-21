/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_itoa(char *str)
{
	int	result = 0;

	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

void	ft_putnbr(int num)
{
	char	digit;

	if (num > 9)
		ft_putnbr(num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);	
}

int	main(int argc, char **argv)
{
	int	num = -1;
	int	sum = 0;
	int	i = 2;
	int	j;
	int	prime;

	if (argc == 2)
		num = ft_itoa(argv[1]);
	if (num != -1)
	{
		while (i <= num)
		{
			prime = 1;
			if (i == 2)
				sum += 2;
			else
			{
				j = 1;
				while (++j < i && prime)
				{
					if (i % j == 0)
						prime = 0;
				}
				if (prime)
					sum += i;
			}
			i++;
		}
		ft_putnbr(sum);
	}
	if (num == -1)
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
