/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:45:05 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/06 17:30:27 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_file(int fd)
{
	char		*buffer;
	int			bytes_read;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return ((char *) -1);
	}
	if (bytes_read == 0)
		return (free(buffer), NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*ft_sort_line(char *buffer, int next_line_index, char **storage)
{
	char	*temp;
	char	*next_line;	

	if (!buffer)
		next_line_index = ft_strchr(*storage, SEPERATOR);
	if (next_line_index != -1)
	{
		next_line = ft_substr(*storage, 0, next_line_index + 1);
		temp = *storage;
		*storage = ft_strdup(temp + next_line_index + 1);
		free(temp);
	}
	else
	{
		next_line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	if (!next_line || *next_line == '\0')
		return (free(next_line), NULL);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	int			next_line_index;
	char		*temp;

	next_line_index = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	while (next_line_index == -1)
	{
		buffer = ft_read_file(fd);
		if (buffer == (char *) -1)
		{
			free(storage);
			storage = NULL;
			return (NULL);
		}
		if (!buffer)
			break ;
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		free(temp);
		free(buffer);
		if (!storage)
			return (NULL);
		next_line_index = ft_strchr(storage, SEPERATOR);
	}
	return (ft_sort_line(buffer, next_line_index, &storage));
}

/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     line_count;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    line_count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_count, line);
        free(line);
        line_count++;
	}
   
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
    
    // Optional: Call GNL one last time to check if it handles EOF gracefully
    line = get_next_line(fd); 
    
    return (0);
}*/