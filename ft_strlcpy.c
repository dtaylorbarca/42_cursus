/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:14:06 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/13 14:42:12 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	if (size == 0)
		return (length);
	while (src[i] != '\0' && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

int	main(void)
{
	char			dest[13];
	char			src[] = "Hello world!";
	unsigned int	length;

	length = ft_strlcpy(dest, src, sizeof(dest));
	printf("Returned length: %u\n", length);
	printf("Dest: \"%s\"\n", dest);
	return (0);
}
