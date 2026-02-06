/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:44:03 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/06 17:19:36 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			length;
	unsigned char	*src_new;

	i = 0;
	length = 0;
	src_new = (unsigned char *) src;
	while (src_new[length] != '\0')
		length++;
	if (size == 0)
		return (length);
	while (src_new[i] != '\0' && i < size)
	{
		dest[i] = src_new[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

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

char	*ft_strdup(const char *src)
{
	size_t			len;
	unsigned char	*dest;

	len = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(unsigned char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy((char *) dest, src, len + 1);
	return ((char *) dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	int		count;

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
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	unsigned char	*i;
	unsigned char	uc;
	int				index;

	i = (unsigned char *) s;
	uc = (unsigned char) c;
	index = 0;
	while (i[index])
	{
		if (i[index] == uc)
			return (index);
		index++;
	}
	return (-1);
}
