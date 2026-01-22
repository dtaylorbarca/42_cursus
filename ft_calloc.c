/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:47:06 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:04:10 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*arr;

	if (nelem == 0 || elsize == 0)
		return (malloc(0));
	if (nelem && elsize > SIZE_MAX / nelem)
		return (0);
	arr = malloc(nelem * elsize);
	if (!arr)
		return (0);
	memset(arr, 0, nelem * elsize);
	return (arr);
}


