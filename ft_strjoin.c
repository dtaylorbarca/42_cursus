/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:54:26 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 19:04:17 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*s1_new;
	unsigned char	*s2_new;
	unsigned char	*str;
	int				len;
	int				count;

	s1_new = (unsigned char *) s1;
	s2_new = (unsigned char *) s2;
	len = ft_strlen(s1_new) + ft_strlen(s2_new);
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (0);
	count = 0;
	while (*s1_new)
	{
		str[count] = *s1_new;
		count++;
		s1_new++;
	}
	while (*s2_new)
	{
		str[count] = *s2_new;
		count++;
		s2_new++;
	}
	return ((char *) str);
}

/*int	main(void)
{
	printf("%s", ft_strjoin("Hello", " Victor"));
	return (0);
}*/
