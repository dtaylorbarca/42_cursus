/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:30:50 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/15 19:12:35 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		count;

	count = 0;
	while (s[count])
	{
		f(count, &s[count]);
		count ++;
	}
	printf("%s", s);
}

void	ft_toupper(unsigned int i, char *c)
{
	i = 0;
	if (97 <= *c && *c <= 122)
		*c -= 32;
}

int	main(void)
{
	char	str[] = "hello";
	ft_striteri(str, ft_toupper);
	return (0);
}
