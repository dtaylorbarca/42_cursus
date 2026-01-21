/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:26:47 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 16:50:59 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (sign == -1)
		return (sign * (int)result);
	return ((int) result);
}

/*int main()
{
    char str[] = " -2147483647";
    int num1;
	int	num2;

    // Convert string to integer
    num1 = ft_atoi(str);
	num2 = atoi(str);

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

    // Convert string to integer using atoi() and 
    // store the result in result_value
    res_val1 = atoi(inp_str);
	res_val2 = ft_atoi(inp_str);

    printf("Input String = %s\nResulting Integer = %d\n", inp_str, res_val1);
	printf("ft_atoi = %d\n", res_val2);

    return 0;
}*/
