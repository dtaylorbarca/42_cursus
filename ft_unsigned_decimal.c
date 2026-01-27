/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:11:05 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/27 16:28:09 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n)
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

static void	ft_nonzero(unsigned int num, char *str_num, int len)
{
	int	num_len;

	num_len = len;
	str_num = malloc((len + 1) * sizeof(char));
	if (!str_num)
		return ;
	str_num[len] = '\0';
	while (len--)
	{
		str_num[len] = num % 10 + 48;
		num /= 10;
	}
	write(1, str_num, num_len);
	free(str_num);
}

int	ft_unsigned_decimal(unsigned int n)
{
	char			*str_num;
	int				len;

	str_num = NULL;
	len = ft_numlen(n);
	if (n == 0)
	{
		str_num = malloc(1 * sizeof(char));
		if (!str_num)
			return (0);
		str_num[0] = '0';
		write(1, str_num, 1);
		free(str_num);
		return (1);
	}
	else
		ft_nonzero(n, str_num, len);
	return (len);
}
