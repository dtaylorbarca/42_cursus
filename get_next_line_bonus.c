/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:45:05 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/12 12:20:19 by dtaylor-         ###   ########.fr       */
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

/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>*/

/*char    *get_next_line(int fd);

static void create_test_files(void)
{
    int fd;

    fd = open("file1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "file1 - line1\nfile1 - line2\nfile1 - line3\n", 42);
    close(fd);

    fd = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "file2 - line1\nfile2 - line2\nfile2 - line3\n", 42);
    close(fd);

    fd = open("file3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "file3 - line1\nfile3 - line2\nfile3 - line3\n", 42);
    close(fd);
}

int main(void)
{
    int     fd1;
    int     fd2;
    int     fd3;
    char    *line;

    create_test_files();

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return (1);
    }

    printf("=== Alternating reads across 3 FDs ===\n");
    int fds[3] = {fd1, fd2, fd3};
    int done[3] = {0, 0, 0};
    int all_done = 0;

    while (!all_done)
    {
        all_done = 1;
        for (int i = 0; i < 3; i++)
        {
            if (done[i])
                continue;
            line = get_next_line(fds[i]);
            if (line)
            {
                printf("[fd%d] %s", i + 1, line);
                free(line);
                all_done = 0;
            }
            else
                done[i] = 1;
        }
    }

    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}*/

/*int	main(void)
{
	int	fd[4];

	fd[0] = open("file1.txt", O_RDONLY);
	fd[1] = open("file2.txt", O_RDONLY);
	fd[2] = open("file3.txt", O_RDONLY);
	fd[3] = open("file4.txt", O_RDONLY);

	printf("\n\n41_with_nl\n");
	printf("--------------------------");
	printf("\n%s", get_next_line(1000));
	printf("\n%s", get_next_line(fd[0]));
	printf("\n\n42_with_nl\n");
	printf("--------------------------");
	printf("\n%s", get_next_line(1001));
	printf("\n%s", get_next_line(fd[1]));
	printf("\n\n43_with_nl\n");
	printf("--------------------------");
	printf("\n%s", get_next_line(1002));
	printf("\n%s", get_next_line(fd[2]));
	printf("\n\n%s", get_next_line(1003));
	printf("\n%s", get_next_line(fd[0]));
	printf("\n\n%s", get_next_line(1004));
	printf("\n%s", get_next_line(fd[1]));
	printf("\n\n%s", get_next_line(1005));
	printf("\n%s", get_next_line(fd[2]));
	printf("\n\n%s", get_next_line(fd[0]));
	printf("\n%s", get_next_line(fd[1]));
	printf("\n%s", get_next_line(fd[2]));
	printf("\n\nnl\n");
	printf("--------------------------");
	printf("\n%s", get_next_line(1006));
	printf("%s", get_next_line(fd[3]));
	printf("\n%s", get_next_line(1007));
	printf("\n%s", get_next_line(fd[3]));
}*/
