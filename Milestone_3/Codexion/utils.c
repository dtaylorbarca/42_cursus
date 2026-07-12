#include "codexion.h"

long long   get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (0);

    return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

int	num_check(char *num)
{
	int	i;
	int	number;

	i = 0;
	while (num[i])
	{
		if ('9' <= num[i] ||  num[i] <= '0')
			return (-1);
		i++;
	}
	number = atoi(num);
	if (number < 1)
		return (-1);
	return (number);
}
