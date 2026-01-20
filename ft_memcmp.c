/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:24:46 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 12:48:11 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_mem;
	unsigned char	*s2_mem;
	size_t			i;

	if (!n || !s1 || !s2)
		return (0);
	s1_mem = (unsigned char *)s1;
	s2_mem = (unsigned char *)s2;
	i = 0;
	while (s1_mem[i] == s2_mem[i] && i < n)
		i++;
	return (s1_mem[i] - s2_mem[i]);
}

/*void run_test(const char *test_name, const void *s1, const void *s2, size_t n) {
    int expected = memcmp(s1, s2, n);
    int actual = ft_memcmp(s1, s2, n);

    // Standard says return value sign matters, not the specific number
    if ((expected == 0 && actual == 0) || 
        (expected < 0 && actual < 0) || 
        (expected > 0 && actual > 0)) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s | Expected sign: %d, Got: %d\n", test_name, expected, actual);
    }
}

int main() {
    printf("Starting memcmp tests...\n\n");

    // 1. Basic Equality
    run_test("Equal strings", "abc", "abc", 3);
    
    // 2. Length 0 (Should always return 0)
    run_test("Zero length", "abc", "xyz", 0);

    // 3. Difference at various positions
    run_test("Difference at start", "abc", "zbc", 3);
    run_test("Difference at end", "abc", "abz", 3);
    
    // 4. Comparison beyond string terminators (Memory is not just strings!)
    char b1[] = {1, 2, 0, 4};
    char b2[] = {1, 2, 0, 5};
    run_test("Comparison after null byte", b1, b2, 4);

    // 5. Unsigned Character Check (Critical)
    // If you use signed chars, 0xFF (255) will be seen as -1, failing this test.
    unsigned char uc1[] = {255, 0};
    unsigned char uc2[] = {0, 255};
    run_test("Unsigned char check (high bit)", uc1, uc2, 2);

    // 6. Long buffers
    char long1[1000], long2[1000];
    memset(long1, 'a', 1000);
    memset(long2, 'a', 1000);
    long2[999] = 'b';
    run_test("Large buffer equality", long1, long1, 1000);
    run_test("Large buffer difference at end", long1, long2, 1000);

    printf("\nTests complete.\n");
    return 0;
}*/