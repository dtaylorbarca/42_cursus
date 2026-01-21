/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:14:06 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 18:03:12 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			length;
	unsigned char	*src_new;

	i = 0;
	length = 0;
	src_new = (unsigned char *) src;
	while (src_new[length] != '\0')
		length++;
	if (size == 0)
		return (length);
	while (src_new[i] != '\0' && i < size -1)
	{
		dest[i] = src_new[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

/*int	main(void)
{
	char			dest[13];
	char			src[] = "Hello world!";
	unsigned int	length;

	length = ft_strlcpy(dest, src, sizeof(dest));
	printf("Returned length: %u\n", length);
	printf("Dest: \"%s\"\n", dest);
	printf("%lu\n", strlcpy(dest, src, sizeof(dest)));
	return (0);
}*/
