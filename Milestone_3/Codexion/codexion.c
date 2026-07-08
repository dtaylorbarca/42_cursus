/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:57:08 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/07/06 21:08:19 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <pthread.h>

int find_digit(char digit)
{
	char *digits;
	int	index;

	digits = "0123456789";
	index = 0;
	while (digits[index])
	{
		if (digit == digits[index])
			return (index);
		index ++;
	}
	return -1;
}

int numtostr(char *num_str)
{
	int len;
	int	result;
	int	i;
	char *digits;

	digits = "0123456789";
	len = strlen(num_str);
	i = 0;
	result = 0;
	while (num_str[i])
	{
		result = result * 10 + find_digit(num_str[i]);
		i++;
	}
	return result;
}

int main(int argc, char **argv)
{
	int num_coders;
	if (argc != 9)
	{
		printf("8 arguments must be provided");
		return (1);
	}
	num_coders = numtostr(argv[1]);
	return (0);
}