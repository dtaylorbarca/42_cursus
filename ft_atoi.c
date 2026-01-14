/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:26:47 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 17:56:51 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;
	unsigned char	*str2;

	i = 0;
	sign = 1;
	result = 0;
	str2 = (unsigned char *) str;
	while (str2[i] == ' ' || (9 <= str2[i] && str2[i] <= 13))
		i++;
	while (str2[i] == '-' || str2[i] == '+')
	{
		if (str2[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str2[i] && str2[i] <= '9')
	{
		result *= 10;
		result += str2[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

/*int main()
{
    char str1[] = "12345";
	char str2[] = "12345";
    int num1;
	int	num2;

    // Convert string to integer
    num1 = atoi(str1);
	num2 = atoi(str2);

    printf("The integer value is: %d\n", num1);
	printf("The integer value is: %d\n", num2);
    return 0;
}*/

/*int main()
{
    int res_val1;
	int	res_val2;
    char inp_str[30];

    // Initializing the input string
    strcpy(inp_str, "-23234");

    // Convert string to integer using atoi() and store the result in result_value
    res_val1 = atoi(inp_str);
	res_val2 = ft_atoi(inp_str);

    printf("Input String = %s\nResulting Integer = %d\n", inp_str, res_val1);
	printf("ft_atoi = %d\n", res_val2);

    return 0;
}*/
