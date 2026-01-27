/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:28:21 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/27 16:35:08 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

int	ft_printf(char const *str, ...);
int	ft_character(int chr);
int	ft_string(char *str);
int	ft_pointer(void *ptr);
int	ft_decimal(int n);
int	ft_unsigned_decimal(unsigned int n);
int	ft_lower_hex(unsigned int n);
int	ft_upper_hex(unsigned int n);

#endif
