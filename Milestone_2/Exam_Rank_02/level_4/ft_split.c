/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

int	count_words(char *str)
{
	int	i = 0;
	int	words = 0;

	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			if (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n')
				words ++;
			i++;
		}
	}
	return (words);
}

int	ft_word_len(char *str)
{
	int	i = 0;
	int	len = 1;

	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
	{
		if (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n')
			return (len);
		i++;
		len++;
	}
	return (len);
}

void	ft_strlcpy(char *dest, char *src, int len)
{
	int	i = 0;

	while (i < len) 
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**fill_words(int words, char *str, char **split)
{
	int	word_len;
	int	j = 0;
	int	i = 0;

	while (j < words)
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		word_len = ft_word_len(&str[i]);
		split[j] = malloc((word_len + 1) * sizeof(char));
		if (!split[j] || word_len == 0)
			return (NULL);
		ft_strlcpy(split[j++], &str[i], word_len);
		i += word_len;
	}
	return (split);
}

char    **ft_split(char *str)
{
	int	words = count_words(str);
	char	**split = malloc((words + 1) * sizeof(char *));

	if (!split)
		return (NULL);
	split = fill_words(words, str, split);
	split[words] = NULL;
	return (split);
}

#include <stdio.h>

int		main(void)
{
	int		i;
	char	**result;

	// Test Case 1: Standard sentence with various delimiters
	char *str1 = "  Hello  world	this is\nGemini ";
	printf("Test 1: [%s]\n", str1);
	result = ft_split(str1);
	i = 0;
	while (result && result[i])
	{
		printf("Word %d: |%s|\n", i, result[i]);
		free(result[i]); // Cleaning up memory
		i++;
	}
	free(result);
	printf("---------------------------\n");

	// Test Case 2: No words (only delimiters)
	char *str2 = "      \t \n  ";
	printf("Test 2: [%s]\n", str2);
	result = ft_split(str2);
	i = 0;
	if (result && !result[i])
		printf("Result is an empty array (Correct)\n");
	free(result);
	printf("---------------------------\n");

	// Test Case 3: Single word
	char *str3 = "Solo";
	printf("Test 3: [%s]\n", str3);
	result = ft_split(str3);
	i = 0;
	while (result && result[i])
	{
		printf("Word %d: |%s|\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}
