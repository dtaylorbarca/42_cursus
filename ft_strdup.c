/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:34:42 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:52 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t			len;
	unsigned char	*dest;

	len = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(unsigned char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy((char *) dest, src, len + 1);
	return ((char *) dest);
}

