/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:24:46 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:09:01 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_mem;
	unsigned char	*s2_mem;
	size_t			i;

	if (!n)
		return (0);
	s1_mem = (unsigned char *)s1;
	s2_mem = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_mem[i] != s2_mem[i])
			return (s1_mem[i] - s2_mem[i]);
		i++;
	}
	return (0);
}
