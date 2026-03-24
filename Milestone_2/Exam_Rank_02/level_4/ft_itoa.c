/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

int	num_len(int nbr)
{
	unsigned int	unbr;
	int	len = 0;

	if (nbr < 0)
	{
		unbr = -nbr;
		len ++;
	}
	else
		unbr = nbr;
	while (unbr > 0)
	{
		len ++;
		unbr /= 10;
	}
	return (len);

}

char	*ft_itoa(int nbr)
{
	int	len = num_len(nbr);
	unsigned int unbr;
	char	*str;
	
	if (nbr == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	else if (nbr < 0)
		unbr = -nbr;
	else
		unbr = nbr;
	str = malloc((len + 1) * sizeof(char));
	str[len] = '\0';
	while (unbr > 0)
	{
		str[--len] = (unbr % 10) + '0';
		unbr /= 10;
	}
	if (nbr < 0)
		str[0] = '-';
	return (str);
}
