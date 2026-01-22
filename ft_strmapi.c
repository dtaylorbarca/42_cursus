/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:32:22 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:06:10 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*new_str;
	size_t			len;
	size_t			count;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (0);
	count = 0;
	while (count < len)
	{
		new_str[count] = f(count, s[count]);
		count ++;
	}
	new_str[count] = '\0';
	return ((char *) new_str);
}

