/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:10:45 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/27 17:26:56 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hex(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count ++;
		n /= 16;
	}
	return (count);
}

static void	ft_put_hex(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_put_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	ft_pointer(void *ptr)
{
	unsigned long	adrs;
	int				len;

	adrs = (unsigned long)ptr;
	if (adrs == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = ft_count_hex(adrs) + 2;
	write(1, "0x", 2);
	ft_put_hex(adrs);
	return (len);
}
