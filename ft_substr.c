/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:02:41 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 18:02:12 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*s1;
	unsigned char	*new;
	size_t	count;

	s1 = (unsigned char *) s;
	new = malloc(len * sizeof(char));
	if (new == NULL)
		return (0);
	count = 0;
	while (count < len)
	{
		new[count] = s1[start];
		count++;
		start++;
	}
	return ((char *) new);
}

/*int	main(void)
{
	char	s[] = "Hello my name is Dylan";
	int		start = 6;
	size_t 	len = 34;

	printf("%s\n", ft_substr(s, start, len));
	return (0);
}*/
