/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:42:41 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 17:55:09 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	if ((char)s2[0] == '\0' || n == 0)
		return ((char *)s1);
	while ((char)s1[i] != '\0' && i < n)
	{
		j = 0;
		c = i;
		while ((char) s1[c] == (char) s2[j])
		{
			j++;
			c++;
			if ((char) s2[j] == '\0')
				return ((char *) &s1[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str1[] = "Hello world!";
	char	str2[] = "Hello world!";
	char	to_find[] = "lo";

	printf("%s\n", ft_strnstr(str1, to_find, 4));
	printf("%s\n", strnstr(str2, to_find, 5));
	return (0);
}*/
