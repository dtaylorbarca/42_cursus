/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:42:41 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:06:16 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	c;

	if (!s2[0])
		return ((char *) s1);
	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i])
	{
		j = 0;
		c = i;
		while (c < n && s1[c] == s2[j])
		{
			j++;
			c++;
			if (s2[j] == '\0')
				return ((char *) &s1[i]);
		}
		i++;
	}
	return (0);
}


