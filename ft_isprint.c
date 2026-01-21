/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:24:12 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 17:56:40 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

/*int	main(void)
{
	int		number = 32;

	while (number <= 127)
	{
		if ((ft_isprint(number) * 16384) != isprint(number))
			printf("Error at %d\n", number);
		number ++;
	}
	return (0);
}*/
