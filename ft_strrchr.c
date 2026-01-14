/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:00 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 18:04:44 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*i;

	i = (unsigned char *) s;
	while (*i)
		i++;
	i--;
	if (c == 0)
	{
		return ((char *) i++);
	}
	while (*i)
	{
		if (*i == c)
			return ((char *) i);
		i--;
	}
	return (0);
}

/*int main()
{
    // initializing string
    char str[] = "GeeksforGeeks";

    // character to be searched
    char chr = 'k';

    // Storing pointer returned by
    char* ptr = ft_strrchr(str, chr);

    char *temp = ptr - str
	// getting the position of the character
    if (ptr) {
        printf("Last occurrence of %c in %s is at index %d",
               chr, str, temp);
    }
    // condition for character not present
    else {
        printf("%c is not present in %s ", chr, str);
    }
    return 0;
}*/

/*int	main(void)
{
	printf("%s\n", ft_strrchr("Hooola", 'l'));
	return (0);
}*/
