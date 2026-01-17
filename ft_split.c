/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:53:57 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/15 14:22:46 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	**ft_malloc(const char *s)
{
	size_t	len;
	char	**split_str;
	int		i;

	len = ft_strlen(s);
	i = 0;
	split_str = malloc((len + 1) * sizeof(char *));
	if (!split_str)
		return (0);
	return (split_str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	size_t	count_s;
	int		count_split;
	int		count_chr;
	int		word_len;
	int		x;

	split_str = ft_malloc(s);
	if (!split_str)
		return (0);
	count_s = 0;
	count_split = 0;
	count_chr = 0;
	x = 0;
	//Maybe if two delimiters in a row, make empty strings in between each delimiter?
	while (s[count_s] == c)
		count_s ++;
	while (s[count_s])
	{
		word_len = 0;
		while(s[count_s] != c)
		{
			word_len ++;
			count_s++;
		}
		split_str[count_split] = malloc(word_len * sizeof(char));
		if (!split_str[count_split])
			return (0);
		while (x < word_len)
		{
			split_str[count_split][count_chr] = s[count_s - word_len];
			count_chr ++;
			count_s ++;
			x ++;
		}
		if (s[count_s] == c && (count_s + 1 < ft_strlen(s)))
		{
			split_str[count_split][count_chr] = '\0';
			count_split ++;
			count_chr = 0;
		}
		else
			count_chr ++;
		count_s ++;
	}
	split_str[count_split] = NULL;
	free(split_str[count_split ++]);
	return (split_str);
}

int	main(void)
{
	char	**split = ft_split("Hello,adios?", ',');

	while (*split)
	{
		printf("%s\n", *split);
		split ++;
	}
	return (0);
}
