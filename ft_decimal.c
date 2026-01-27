/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:10:23 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/27 18:09:28 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

static void	ft_putnbr(int n, char *num)
{
	unsigned int	mod;
	int				count;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		mod = -n;
	}
	else
		mod = n;
	count = 0;
	while (mod > 0)
	{
		num[count++] = (mod % 10) + '0';
		mod /= 10;
	}
	while (count -- > 0)
		write(1, &num[count], 1);
}

int	ft_decimal(int n)
{
	int		len;
	char	*result;

	len = ft_numlen(n);
	if (n < 0)
		len++;
	result = malloc(len);
	if (!result)
		return (0);
	ft_putnbr(n, result);
	free(result);
	return (len);
}
