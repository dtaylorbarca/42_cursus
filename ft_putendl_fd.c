/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:20:16 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 14:30:07 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, sizeof(char));
		s++;
	}
	write(fd, "\n", sizeof(char));
}

/*int	main(void)
{
	ft_putendl_fd("hello", 1);
	return (0);
}*/
