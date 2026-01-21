/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:52:25 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 17:56:13 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
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
