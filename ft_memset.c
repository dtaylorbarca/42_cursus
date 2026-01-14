/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:57:15 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/14 17:23:31 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t len)
{ 
	char	*p;

	p = (char*) str;
	while (len > 0)
	{
		*p = c;
		p ++;
		len --;
	}
	return (str);
}

/*int	main(void)
{
	int n = 10;
    int arr_1[n];
	int arr_2[n];
	int	i = 0;

	memset(arr_1, 0, n * sizeof(arr_1[0]));
	ft_memset(arr_2, 0, n * sizeof(arr_2[0]));

	printf("After memset()\n");
	while (i < n)
	{
		printf("%d ", arr_1[i]);
		i++;
	}
	printf("\nAfter ft_memset(): \n");
	i = 0;
	while (i < n)
	{
		printf("%d ", arr_2[i]);
		i ++;
	}
	char	str_1[50] = "GeeksForGeeks is for programming geeks.";
	char	str_2[50] = "GeeksForGeeks is for programming geeks.";

	printf("\nBefore memset(): %s\n", str_1);
	memset(str_1 + 13, '.', 8*sizeof(char));
	ft_memset(str_2 + 13, '.', 8*sizeof(char));
	printf("After memset():  %s\n", str_1);
	printf("After ft_memset():  %s\n", str_2);
	return (0);
}*/
