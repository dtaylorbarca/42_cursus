/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:18:39 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/13 15:01:52 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_mem;
	char	*src_mem;
	char	temp[100];
	size_t	i;

	dest_mem = (char *) dest;
	src_mem = (char *) src;
	i = 0;
	while (i < n)
	{
		temp[i] = src_mem[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_mem[i] = temp[i];
		i++;
	}
	return (dest);
}

int main() 
{ 
	char csrc[100] = "Geeksfor"; 
	ft_memmove(csrc+5, csrc, strlen(csrc)+1); 
	printf("%s", csrc); 
	return 0; 
}
