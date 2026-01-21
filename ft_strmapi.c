/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:32:22 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 18:05:31 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*new_str;
	size_t			len;
	size_t			count;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (0);
	count = 0;
	while (count < len)
	{
		new_str[count] = f(count, s[count]);
		count ++;
	}
	new_str[count] = '\0';
	return ((char *) new_str);
}

/*// --- Test Mapping Functions ---

// 1. Alternating Case: Uppercase even indices, lowercase odd indices
char test_alternating_case(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (char)toupper((unsigned char)c);
	return (char)tolower((unsigned char)c);
}

// 2. Index Offset: Shifting characters by their index (a -> a, b -> c, etc.)
char test_index_shift(unsigned int i, char c)
{
	return (char)(c + i);
}

// --- Test Runner ---

void run_test(char const *s, char (*f)(unsigned int, char), 
	const char *test_name)
{
	printf("Test: %s\n", test_name);
	printf("Input String: \"%s\"\n", s ? s : "NULL");

	char *result = ft_strmapi(s, f);

	if (result == NULL)
	{
		printf("Result: NULL (Allocation failed or NULL input)\n");
	}
	else
	{
		printf("Result: \"%s\"\n", result);
		free(result); // Crucial: strmapi allocates new memory
	}
	printf("-------------------------------------------\n");
}

int main(void)
{
	printf("--- Starting strmapi Tests ---\n\n");

	// 1. Standard Alpha Test
	run_test("abcdef", test_alternating_case, "Alternating Case (Even=Upper)");

	// 2. Index Influence Test
	// 'a' + 0 = 'a', 'a' + 1 = 'b', 'a' + 2 = 'c'...
	run_test("aaaaa", test_index_shift, "Index Shift (c + i)");

	// 3. Empty String
	run_test("", test_alternating_case, "Empty String");

	// 4. Numerical/Special Characters
	run_test("12345 !@#", test_index_shift, "Non-Alpha Characters");

	// 5. NULL Input (Handling protection)
	run_test(NULL, test_alternating_case, "NULL Input String Protection");

	printf("\n--- Tests Complete ---\n");
	return (0);
}
*/