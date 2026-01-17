/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:04:54 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/15 12:50:47 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_dup(char const *s1, char const *set, int count_s1, int count_set)
{
	while (s1[count_s1] == set[count_set])
		count_s1++;
	return (count_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*trimmed;
	size_t			len;
	int				count_trim;
	int				count_s1;
	int				count_set;

	len = ft_strlen(s1);
	trimmed = malloc(len * sizeof(char));
	if (trimmed == NULL)
		return (0);
	count_trim = 0;
	count_s1 = 0;
	while (s1[count_s1])
	{
		count_set = 0;
		while (set[count_set])
		{
			count_s1 = ft_dup(s1, set, count_s1, count_set);
			count_set++;
		}
		trimmed[count_trim] = s1[count_s1];
		count_s1++;
		count_trim++;
	}
	return ((char *) trimmed);
}

int	main(void)
{
	printf("%s\n", ft_strtrim("Hello my name is Dylan", "el"));
	return (0);
}
