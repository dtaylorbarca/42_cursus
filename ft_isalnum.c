/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:38 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 17:55:30 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*int	main(void)
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
}*/
