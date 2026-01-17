/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:34:42 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 19:02:13 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(unsigned char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_strcpy(unsigned char *dest, unsigned char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(const char *src)
{
	int				len;
	unsigned char	*dest;
	unsigned char	*src_new;

	src_new = (unsigned char *) src;
	len = ft_strlen(src_new);
	dest = malloc(len * sizeof(char));
	ft_strcpy(dest, src_new);
	return ((char *) dest);
}

/*int	main(void)
{
	char	src[] = "Hello!";
	char	*dest = ft_strdup(src);
	printf("%s", dest);
}*/
