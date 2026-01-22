/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:18:39 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 14:06:38 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned char	*ft_destmem(unsigned char *dest, unsigned char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_mem;
	unsigned char	*src_mem;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dest_mem = (unsigned char *) dest;
	src_mem = (unsigned char *) src;
	i = 0;
	if (dest_mem < src_mem)
	{
		while (i < n)
		{
			dest_mem[i] = src_mem[i];
			i++;
		}
	}
	else
	{
		dest_mem = ft_destmem(dest_mem, src_mem, n);
	}
	return (dest);
}

/*int main() 
{ 
	char csrc1[100] = "Geeksfor";
	char csrc2[100] = "Geeksfor";
	memmove(csrc1+5, csrc1, strlen(csrc1)+1);  
	ft_memmove(csrc2+5, csrc2, strlen(csrc2)+1); 
	printf("memmove: %s\n", csrc1);
	printf("ft_memmove: %s\n", csrc2);
	return 0; 
}*/
