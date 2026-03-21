/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	range = 0;
	int	*nbrs;
	int	i = 0;

	if (end >= start)
		range = end - start;
	else
		range = start - end;
	nbrs = malloc((range + 1) * sizeof(int));
	if (end >= start)
	{
		while (end >= start)
			nbrs[i++] = end --;
	}
	else
	{
		while (end <= start)
			nbrs[i++] = end ++;
	}
	return (nbrs);
}
