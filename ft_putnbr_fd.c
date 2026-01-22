/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:22:40 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 12:18:33 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	mod;
	int				count;
	char			num[11];

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		mod = -n;
	}
	else
		mod = n;
	count = 0;
	while (mod > 0)
	{
		num[count++] = (mod % 10) + '0';
		mod /= 10;
	}
	while (count -- > 0)
		write(fd, &num[count], 1);
}

/*int	main(void)
{
	ft_putnbr_fd(411, 1);
}*/
