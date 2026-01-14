/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:52:25 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 17:20:22 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	int		string = 126;
	int		number;

	number = ft_isascii(string);
	printf("isascii = %d\n", isascii(string));
	printf("ft_isascii = %d\n", number);
	return (0);
}*/
