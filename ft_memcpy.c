/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:43:29 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 18:00:54 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_mem;
	unsigned char	*src_mem;
	size_t			i;

	dest_mem = (unsigned char *) dest;
	src_mem = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*dest_mem = *src_mem;
		dest_mem++;
		src_mem++;
		i++;
	}
	return (dest);
}

/*int main() {

    // Initialize a variable
    int a = 20;
    int b = 10;
    
    printf("Value of b before calling memcpy: %d\n", b);

    // Use memcpy to copy the value of 'a' into 'b'
    memcpy(&b, &a, sizeof(int)); 
    printf("Value of b after calling memcpy: %d\n", b);

    return 0;
}*/

/*int main() {
    char str1[] = "Geeks";
    char str2[] = "hola que tal";

    // Copies contents of str1 to str2
    ft_memcpy(str2, str1, sizeof(str1));

    printf("str2 after memcpy: ");
    printf("%s",str2);

    return 0;
}*/

/*int main() 
{ 
	char csrc[100] = "Geeksfor"; 
	ft_memcpy(csrc+5, csrc, strlen(csrc)+1); 
	printf("%s", csrc); 
	return 0; 
}*/
