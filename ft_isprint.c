/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:24:12 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 19:04:43 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c <= 33 && c <= 126)
		return (0);
	return (1);
}

/*int	main(void)
{
	int		string = 20;
	int		number;

	number = ft_isprint(string);
	printf("isprint = %d\n", isprint(string));
	printf("ft_isprint = %d\n", number);
	return (0);
}*/
