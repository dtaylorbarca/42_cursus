/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:54:26 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:05:58 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*str;
	size_t			len;
	int				count;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	count = 0;
	while (*s1)
	{
		str[count] = (unsigned char) *s1;
		count++;
		s1++;
	}
	while (*s2)
	{
		str[count] = (unsigned char) *s2;
		count++;
		s2++;
	}
	str[count] = '\0';
	return ((char *) str);
}
