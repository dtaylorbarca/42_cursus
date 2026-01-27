/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:01:54 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/27 16:58:20 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	percent(char const *str, va_list param)
{
	int	count;

	count = 0;
	if (!*str)
		return (0);
	else if (*str == '%')
	{
		write(1, "%%", 1);
		count = 1;
	}
	else if (*str == 'c')
		count = ft_character(va_arg(param, int));
	else if (*str == 's')
		count = ft_string(va_arg(param, char *));
	else if (*str == 'p')
		count = ft_pointer(va_arg(param, void *));
	else if (*str == 'd' || *str == 'i')
		count = ft_decimal(va_arg(param, int));
	else if (*str == 'u')
		count = ft_unsigned_decimal(va_arg(param, unsigned int));
	else if (*str == 'x')
		count = ft_lower_hex(va_arg(param, unsigned int));
	else if (*str == 'X')
		count = ft_upper_hex(va_arg(param, unsigned int));
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
			count += percent(++ str, param);
			str++;
		}
	}
	return (count);
}
