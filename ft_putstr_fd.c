/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:17:59 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 14:30:30 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, sizeof(char));
		s++;
	}
}

/*int	main(void)
{
	ft_putstr_fd("hello", 0);
	return (0);
}*/
