/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:10:33 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/02 13:09:54 by dtaylor-         ###   ########.fr       */
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

static void	ft_put_hex(unsigned int n, char	*base)
{
	if (n >= 16)
		ft_put_hex(n / 16, base);
	write(1, &base[n % 16], 1);
}

int	ft_hex(unsigned int n, char	*base)
{
	int		len;

	len = ft_count_hex(n);
	ft_put_hex(n, base);
	return (len);
}
