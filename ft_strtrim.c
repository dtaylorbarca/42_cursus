/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:04:54 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 18:16:05 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	size_t			start;
	size_t			end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end --;
	if (end <= start)
		return (strdup(""));
	trimmed = malloc((end - start + 1) * sizeof(char));
	if (trimmed == NULL)
		return (0);
	ft_strlcpy(trimmed, &s1[start], end - start + 1);
	return (trimmed);
}

/*int	main(void)
{
	printf("%s\n", ft_strtrim("tripouille    xxx", " x"));
	return (0);
}*/
