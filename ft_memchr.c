/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:02:56 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:09 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_mem;
	size_t			i;

	s_mem = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*s_mem == (unsigned char) c)
			return (s_mem);
		s_mem++;
		i++;
	}
	return (NULL);
}

