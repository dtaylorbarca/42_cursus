/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:45:05 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/12 12:24:04 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_read_and_append(int fd, char **storage)
{
	int		bytes_read;
	char	*temp;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-2);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (free(buffer), -2);
	if (bytes_read == 0)
		return (free(buffer), -3);
	buffer[bytes_read] = '\0';
	temp = *storage;
	*storage = ft_strjoin(temp, buffer);
	free(temp);
	free(buffer);
	if (!*storage)
		return (-2);
	return (ft_strchr(*storage, SEPERATOR));
}

static char	*ft_new_line(int next_line_index, char **storage)
{
	char	*next_line;
	char	*temp;

	next_line = ft_substr(*storage, 0, next_line_index + 1);
	if (!next_line)
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	temp = *storage;
	*storage = ft_strdup(temp + next_line_index + 1);
	if (!*storage)
	{
		free(temp);
		free(next_line);
		return (NULL);
	}
	free(temp);
	return (next_line);
}

static char	*ft_sort_line(int next_line_index, char **storage)
{
	char	*next_line;

	if (!storage || !*storage)
		return (NULL);
	if (next_line_index >= 0)
		return (ft_new_line(next_line_index, storage));
	next_line = ft_strdup(*storage);
	free(*storage);
	*storage = NULL;
	if (!next_line)
		return (NULL);
	if (*next_line == '\0')
		return (free(next_line), NULL);
	return (next_line);
}

static int	ft_read_until_newline(int fd, char **storage)
{
	int	next_line_index;

	next_line_index = ft_strchr(*storage, SEPERATOR);
	while (next_line_index == -1)
	{
		next_line_index = ft_read_and_append(fd, storage);
		if (next_line_index == -2 || next_line_index == -3)
			return (next_line_index);
	}
	return (next_line_index);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	int			next_line_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	if (!storage[fd])
		return (NULL);
	next_line_index = ft_read_until_newline(fd, &storage[fd]);
	if (next_line_index == -2)
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	if (next_line_index == -3 && (!storage[fd] || !*storage[fd]))
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	if (next_line_index == -3)
		return (ft_sort_line(-1, &storage[fd]));
	return (ft_sort_line(next_line_index, &storage[fd]));
}
