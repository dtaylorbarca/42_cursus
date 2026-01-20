/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:22:40 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 14:37:56 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*x;

	x = ft_itoa(n);
	while (*x)
	{
		write(fd, &*x, sizeof(char));
		x++;
	}
}

/*int	main(void)
{
	ft_putnbr_fd(411, 1);
}*/
