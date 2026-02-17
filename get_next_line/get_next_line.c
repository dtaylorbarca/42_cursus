/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:45:05 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/12 11:26:39 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*storage;
	int			next_line_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	if (!storage)
		return (NULL);
	next_line_index = ft_read_until_newline(fd, &storage);
	if (next_line_index == -2)
		return (free(storage), storage = NULL, NULL);
	if (next_line_index == -3 && (!storage || !*storage))
		return (free(storage), storage = NULL, NULL);
	if (next_line_index == -3)
		return (ft_sort_line(-1, &storage));
	return (ft_sort_line(next_line_index, &storage));
}

/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h" // Replace with your header name

int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int     line_count;

    if (argc < 2)
    {
        printf("Usage: ./a.out <filename>\n");
        return (1);
    }
    
    // 1. Open the file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    line_count = 1;
    // 2. The loop: call GNL until it returns NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_count, line);
        
        // 3. IMPORTANT: Free the line returned by GNL
        free(line);
        line_count++;
    }
	printf("\n%s", line);
	free(line);
    // 4. Close the file descriptor
    close(fd);
    
    // Optional: Call GNL one last time to check if it handles EOF gracefully
    // line = get_next_line(fd); 
    
    return (0);
}*/