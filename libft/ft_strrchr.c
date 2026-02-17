/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:00 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:09:51 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*i;
	unsigned char	uc;

	i = (unsigned char *) s;
	uc = (unsigned char) c;
	while (*i)
		i++;
	if (uc == 0)
	{
		return ((char *) i);
	}
	while (i > (unsigned char *) s)
	{
		i--;
		if (*i == uc)
			return ((char *) i);
	}
	return (NULL);
}
