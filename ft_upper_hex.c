/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:09:53 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/27 17:45:09 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hex(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count ++;
		n /= 16;
	}
	return (count);
}

static void	ft_put_hex(unsigned int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_put_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	ft_upper_hex(unsigned int n)
{
	int		len;

	len = ft_count_hex(n);
	ft_put_hex(n);
	return (len);
}
