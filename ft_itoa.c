/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:15:14 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:08:35 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

static char	*ft_nonzero(int n, char *str_num, unsigned int num, int len)
{
	if (n < 0)
	{
		len++;
		num = -n;
	}
	else
		num = n;
	str_num = malloc((len + 1) * sizeof(char));
	if (!str_num)
		return (NULL);
	str_num[len] = '\0';
	while (len--)
	{
		str_num[len] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}

char	*ft_itoa(int n)
{
	char			*str_num;
	unsigned int	num;
	int				len;

	str_num = NULL;
	num = 0;
	len = ft_numlen(n);
	if (n == 0)
	{
		num = n;
		str_num = malloc(2 * sizeof(char));
		if (!str_num)
			return (NULL);
		str_num[0] = num + 48;
		str_num[1] = '\0';
	}
	else
	{
		str_num = ft_nonzero(n, str_num, num, len);
	}
	return (str_num);
}
