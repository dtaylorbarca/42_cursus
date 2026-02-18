/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:01:54 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/18 15:39:32 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	percent(char c, va_list param)
{
	int	count;

	count = 0;
	if (!c)
		return (0);
	else if (c == '%')
	{
		write(1, "%%", 1);
		count = 1;
	}
	else if (c == 'c')
		count = ft_character(va_arg(param, int));
	else if (c == 's')
		count = ft_string(va_arg(param, char *));
	else if (c == 'p')
		count = ft_pointer(va_arg(param, void *));
	else if (c == 'd' || c == 'i')
		count = ft_decimal(va_arg(param, int));
	else if (c == 'u')
		count = ft_unsigned_decimal(va_arg(param, unsigned int));
	else if (c == 'x')
		count = ft_hex(va_arg(param, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count = ft_hex(va_arg(param, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	param;

	va_start(param, str);
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str != '%')
		{
			write(1, str, 1);
			str++;
			count++;
		}
		if (*str == '%')
		{
			str++;
			count += percent(*str, param);
			if (*str)
				str++;
		}
	}
	va_end(param);
	return (count);
}
