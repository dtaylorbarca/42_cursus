/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:00 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:09:23 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*i;
	unsigned char	uc;

	i = (unsigned char *) s;
	uc = (unsigned char) c;
	if (uc == '\0')
	{
		while (*i)
			i++;
		return ((char *) i);
	}
	while (*i)
	{
		if (*i == uc)
			return ((char *) i);
		i++;
	}
	return (NULL);
}
