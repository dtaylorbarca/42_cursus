/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:19:11 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/12 16:38:33 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
			return (0);
	return (1);
}

int	main(void)
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
}
