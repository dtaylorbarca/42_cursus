/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:38 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/12 16:46:21 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
			return (0);
	return (1);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0); 
}

int	main(void)
{
	char	string = '	';
	int		number;

	number = ft_isalnum(string);
	if (isalnum(string))
	{
        printf("%c is Alphanumeric\n", string);
		printf("%d\n", number);
	}
    else
	{
        printf("%c is NOT Alphanumeric\n", string);
  		printf("%d\n", number);
	}
	return (0);
}
