/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:00 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 14:01:22 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*i;
	unsigned char	uc;

	i = (unsigned char *) s;
	uc = (unsigned char) c;
	if (uc == '\0')
	{
		while (*i)
			i++;
		return ((char *) i);
	}
	while (*i)
	{
		if (*i == uc)
			return ((char *) i);
		i++;
	}
	return (NULL);
}

/*void run_test(const char *test_name, const char *s, int c) {
    char *expected = strchr(s, c);
    char *actual = ft_strchr(s, c);

    if (expected == actual) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s | Expected pointer: %p, 
		Got: %p\n", test_name, (void*)expected, (void*)actual);
        if (expected && actual) {
            printf("       Values at pointers: 
			Expected '%c', Got '%c'\n", *expected, *actual);
        }
    }
}

int main() {
    printf("Starting strchr tests...\n\n");

    // 1. Basic success cases
    run_test("Find middle char", "Hello World", 'o');
    run_test("Find first char", "Hello World", 'H');
    run_test("Find last char", "Hello World", 'd');

    // 2. Character not present
    run_test("Character not found", "Hello", 'z');

    // 3. The Null Terminator (Critical Edge Case)
    // strchr MUST be able to return a pointer to the '\0'
    run_test("Find null terminator", "Hello", '\0');

    // 4. Empty string
    run_test("Empty string, searching for char", "", 'a');
    run_test("Empty string, searching for null", "", '\0');

    // 5. Repeated characters
    // Should return the FIRST occurrence
    run_test("First of multiple", "banana", 'a');

    // 6. High-bit characters (int to char conversion)
    // The character is passed as an int but interpreted as a char
    run_test("Character with high bit", "test \xFF string", (char)255);

    printf("\nTests complete.\n");
    return 0;
}*/