/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:47:06 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/16 18:42:11 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*arr;

	if (nelem == 0 || elsize == 0)
		return (malloc(0));
	if (nelem && elsize > SIZE_MAX / nelem)
		return (0);
	arr = malloc(nelem * elsize);
	if (!arr)
		return (0);
	memset(arr, 0, nelem * elsize);
	return (arr);
}

/*void test_calloc(size_t nmemb, size_t size, const char *test_name)
{
    printf("Test: %s (%zu elements of %zu bytes)\n", test_name, nmemb, size);

    // 1. Call your function
    void *ptr = ft_calloc(nmemb, size);

    // 2. Handle NULL returns (could be intentional or a failure)
    if (ptr == NULL)
    {
        if (nmemb == 0 || size == 0)
            printf("Result: NULL (Expected for 0-size request)\n");
        else if (nmemb > SIZE_MAX / size)
            printf("Result: NULL (Expected for Overflow)\n");
        else
            printf("Result: NULL (Allocation Failed)\n");
        printf("-------------------------------------------\n");
        return;
    }

    // 3. Check if memory is actually zeroed out
    // We create a "reference" block of zeroes to compare against
    unsigned char *check_ptr = (unsigned char *)ptr;
    int is_zero = 1;
    for (size_t i = 0; i < (nmemb * size); i++)
    {
        if (check_ptr[i] != 0)
        {
            is_zero = 0;
            break;
        }
    }

    if (is_zero)
        printf("Result: SUCCESS (Memory is zero-initialized)\n");
    else
        printf("Result: FAILURE (Memory contains garbage values!)\n");

    // 4. Free the memory
    free(ptr);
    printf("-------------------------------------------\n");
}

int main(void)
{
    printf("--- Starting calloc Tests ---\n\n");

    // Standard allocations
    test_calloc(10, sizeof(int), "Standard Int Array");
    test_calloc(50, 1, "Small Char Array");
    test_calloc(1, 1000, "Single Large Block");

    test_calloc(0, 10, "Zero Elements");
    test_calloc(10, 0, "Zero Size");
    test_calloc(0, 0, "Both Zero");

    // Overflow case (Total size would exceed size_t capacity)
    // This tests if you have the (nmemb > SIZE_MAX / size) check
    test_calloc(SIZE_MAX, 2, "Integer Overflow Test");

    // Large allocation (Should likely fail and return NULL)
    test_calloc(SIZE_MAX, 1, "Impossible Size");

    printf("\n--- Tests Complete ---\n");
    return (0);
}*/
