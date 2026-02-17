/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:28:22 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/02/17 14:27:35 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# ifndef SEPERATOR
#  define SEPERATOR '\n'
# endif

# define FD_MAX 1024

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif