/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:19:11 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 17:56:31 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (!(c >= '0' && c <= '9'));
}

/*int	main(void)
{
	char	string = '9';
	int		number;

	number = ft_isdigit(string);
	if (isdigit(string))
	{
        printf("%c is Numeric\n", string);
		printf("%d\n", number);
	}
    else
	{
        printf("%c is NOT Numeric\n", string);
  		printf("%d\n", number);
	}
	return (0);
}*/
