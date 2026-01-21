/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:02:41 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 12:56:50 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	count;
	
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	count = 0;
	while (count < len)
	{
		new[count] = s[start + count];
		count ++;
	}
	new[count] = '\0';
	return (new);
}

/*int	main(void)
{
	char	s[] = "tripouille";
	int		start = 100;
	size_t 	len = 1;
	char	*str = ft_substr(s, start, len);
	
	printf("%s\n", str);
	free(str);
	return (0);
}*/
