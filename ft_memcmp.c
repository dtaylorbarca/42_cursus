/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:24:46 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 18:59:45 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_mem;
	unsigned char	*s2_mem;
	size_t			i;

	s1_mem = (unsigned char *)s1;
	s2_mem = (unsigned char *)s2;
	i = 0;
	while (s1_mem[i] == s2_mem[i] && i < n)
		i++;
	return (s1_mem[i] - s2_mem[i]);
}

/*int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "Hello\0asdoijjasoij";
	int		n = 10;

	printf("memcmp: %d\n", memcmp(str1, str2, n));
	printf("ft_memcmp: %d\n", ft_memcmp(str1, str2, n));
	return (0);
}*/

/*int main() {
    int res = 0;
    char s1[10] = "geeks";
    char s2[10] = "greeks";

    // Use memcmp() to compare s1 and s2 up to
  	// length of s1
    res = ft_memcmp(s1, s2, strlen(s1));

    // Check the result of memcmp
    if (res > 0)
        printf("s1 is greater");
    else if (res < 0)
        printf("s2 is greater");
    else
        printf("both are equal");

    return 0;
}*/
