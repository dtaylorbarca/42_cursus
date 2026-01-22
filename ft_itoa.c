/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:15:14 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 14:10:13 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

static char	*ft_nonzero(int n, char *str_num, unsigned int num, int len)
{
	if (n < 0)
	{
		len++;
		num = -n;
	}
	else
		num = n;
	str_num = malloc((len + 1) * sizeof(char));
	if (!str_num)
		return (NULL);
	str_num[len] = '\0';
	while (len--)
	{
		str_num[len] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}

char	*ft_itoa(int n)
{
	char			*str_num;
	unsigned int	num;
	int				len;

	str_num = NULL;
	num = 0;
	len = ft_numlen(n);
	if (n == 0)
	{
		num = n;
		str_num = malloc(2 * sizeof(char));
		if (!str_num)
			return (NULL);
		str_num[0] = num + 48;
		str_num[1] = '\0';
	}
	else
	{
		str_num = ft_nonzero(n, str_num, num, len);
	}
	return (str_num);
}

/*void test_itoa(int n)
{
    char *result = ft_itoa(n);
    
    if (result == NULL)
    {
        printf("Input: %11d | Result: NULL (Allocation Failed)\n", n);
        return;
    }
    
    printf("Input: %11d | Result: \"%s\"\n", n, result);
    
    // Crucial: free the memory allocated by your itoa
    free(result);
}

int main(void)
{
    printf("--- Starting itoa Tests ---\n\n");

    // 1. Basic Tests
    printf("Basic Tests:\n");
    test_itoa(0);
    test_itoa(7);
    test_itoa(-9);
    test_itoa(42);
    test_itoa(-42);

    printf("\nMulti-digit Tests:\n");
    test_itoa(100);
    test_itoa(1024);
    test_itoa(-12345);
    test_itoa(987654321);

    // 2. Limit Tests (The most important ones!)
    printf("\nEdge Case Tests:\n");
    test_itoa(INT_MAX);  // 2147483647
    test_itoa(INT_MIN);  // -2147483648 (Check if your code crashes here!)

    printf("\n--- Tests Complete ---\n");
	return (0);
}*/
