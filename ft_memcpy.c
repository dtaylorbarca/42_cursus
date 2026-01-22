/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:43:29 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:19 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_mem;
	unsigned char	*src_mem;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dest_mem = (unsigned char *) dest;
	src_mem = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*dest_mem = *src_mem;
		dest_mem++;
		src_mem++;
		i++;
	}
	return (dest);
}

