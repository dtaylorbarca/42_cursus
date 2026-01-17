/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:16:41 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 18:59:28 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_new;
	unsigned char	*s2_new;

	s1_new = (unsigned char *) s1;
	s2_new = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (s1_new[i] && s2_new[i] && s1_new[i] == s2_new[i] && i < n - 1)
		i++;
	if (i == n)
		return (0);
	return (s1_new[i] - s2_new[i]);
}

/*int	main(void)
{
	char	s1[] = "\0";
	char	s2[] = "adcd";

	printf("%d",ft_strncmp(s1, s2, 2));
	return (0);
}*/
