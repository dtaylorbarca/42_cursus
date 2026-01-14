/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:00 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 17:41:24 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char *i;

	i = (unsigned char *) s;
	if (c == '\0')
	{
		while (*i)
			i++;
		return ((char *) i);
	}
	while (*i)
	{
		if (*i == c)
			return ((char *) i);
		i++;
	}
	return (0);
}

/*int main()
{
    // define a string
    const char* str = "GeeksforGeeks";
    // define a char ch to be searched in str
    char ch = 's';

    // Use strchr to find the first occurrence of the
    // character 's'
    const char* result = ft_strchr(str, ch);

    if (result != NULL) {
        // Calculate the position by subtracting the base
        // pointer from the result pointer
        printf("Character '%c' found at position: %ld\n",
               ch, result - str);
    }
    else {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}*/

/*int main()
{
    // Original string containing username and password
    const char* str = "GeeksforGeeks:abc@123";
    // Delimiter to separate username and password

    char delimiter = ':';
    // Find the position of the delimiter in the string
    char* delimiter_position = ft_strchr(str, delimiter);

    // If the delimiter is found in the string
    if (delimiter_position != NULL) {
        // Calculate the length of the username
        size_t username_length = delimiter_position - str;

        // Allocate memory for the username and copy the
        // username part of the string
        char username[username_length + 1];
        strncpy(username, str, username_length);

        // Null-terminate the username string
        username[username_length] = '\0';

        // The password starts right after the delimiter
        char* password = delimiter_position + 1;

        // Print the extracted username and password
        printf("Username: %s\n", username);
        printf("Password: %s\n", password);
    }
    else {
        // If the delimiter is not found, print an error
        // message
        printf("Delimiter not found.\n");
    }

    return 0;
}*/

/*int	main(void)
{
	printf("%s", ft_strchr("hoola", 'i'));
}*/
