/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:34:42 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 13:52:13 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t			len;
	unsigned char	*dest;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(unsigned char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy((char *) dest, src, len);
	return ((char *) dest);
}

/*int	main(void)
{
	char	src[] = "";
	char	*dest = strdup(src);
	printf("%s", dest);
}*/
