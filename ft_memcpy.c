/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:43:29 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/13 14:17:46 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *restrict dest, void *restrict src, size_t  n)
{
	char	*dest_mem;
	char	*src_mem;
	size_t	i;

	dest_mem = (char *) dest;
	src_mem = (char *) src;
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
    ft_memcpy(&b, &a, sizeof(int)); 

    printf("Value of b after calling memcpy: %d\n", b);

    return 0;
}*/

int main() {
    char str1[] = "Geeks";
    char str2[6] = "";

    // Copies contents of str1 to str2
    ft_memcpy(str2, str1, sizeof(str1));

    printf("str2 after memcpy:");
    printf("%s",str2);

    return 0;
}
