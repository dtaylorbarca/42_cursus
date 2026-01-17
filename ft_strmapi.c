/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:32:22 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/15 18:44:09 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*new_str;
	size_t			len;
	size_t			count;

	len = ft_strlen(s);
	new_str = malloc(len * sizeof(char));
	count = 0;
	if (new_str == NULL)
		return (0);
	while (count < len)
	{
		new_str[count] = f(count, s[count]);
		count ++;
	}
	return ((char *) new_str);
}

/*char	ft_toupper(unsigned int i, char c)
{
	i = 0;
	if (97 <= c && c <= 122)
		c -= 32;
	return (c);
}

int	main(void)
{
	printf("%s", ft_strmapi("hello", ft_toupper));
	return (0);
}*/
