/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:58:29 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/13 14:09:00 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s; 
	while (i < n)
	{
		*p = '\0';
		p++;
		i++;
	}
}

int	main() {
	char s[] = "meow";
	size_t n = 0;

	ft_bzero(s, n);
	for (size_t i = 0; i < n; i++)
		printf("%d ", s[i]); 
}
