/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:02:56 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 13:48:36 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_mem;
	size_t			i;

	s_mem = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*s_mem == (unsigned char) c)
			return (s_mem);
		s_mem++;
		i++;
	}
	return (NULL);
}

/*int main (void) 
{
   const char str[] = "Tutorialspoint";
   const char ch = '.';
   char *ret;
   ret = ft_memchr(str, ch, 1);
   printf("String after |%c| is - |%s|\n", ch, ret);
   return(0);
}*/

/*int main() {
   const char str1[] = "abcdef";
   const char ch = 'd';

   char* result = (char*) ft_memchr(str1, ch, strlen(str1));

   if (result != NULL) {
       printf("'%c' found at position %ld\n", ch, result - str1);
   } else {
       printf("'%c' not found in the string\n", ch);
   }

   return 0;
}*/

/*int main() {
   const char str[] = "Welcome to India";
   const char ch = 't';

   char* result = (char*)memchr(str, ch, strlen(str));

   if (result != NULL) {
       printf("'%c' found at position %ld\n", ch, result - str);
   } else {
       printf("'%c' not found in the string\n", ch);
   }
   
   return 0;
}*/
