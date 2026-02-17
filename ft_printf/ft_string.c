/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:10:58 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/27 17:46:36 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *str)
{
	size_t	i;
	size_t	len;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	return ((int) len);
}
