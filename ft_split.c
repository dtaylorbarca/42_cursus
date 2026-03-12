/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:44:52 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 16:14:43 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(const char *str, char c)
{
	int	words;
	int	current_word;
	int	i;

	words = 0;
	current_word = 0;
	i = 0;
	while (str[i])
	{
		if (current_word == 0 && str[i] != c)
		{
			current_word = 1;
			words++;
		}
		else if (str[i] == c)
		{
			current_word = 0;
		}
		i++;
	}
	return (words);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	init_var(size_t *i, int *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**resul;
	size_t	i;
	int		j;
	int		start_word;

	init_var(&i, &j, &start_word);
	resul = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!resul)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			resul[j] = fill_word(s, start_word, i);
			if (!(resul[j]))
				return (ft_free(resul, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	return (resul);
}
