*This project has been created as part of the 42 curriculum by dtaylor-*

# 42cursus - Libft

---

# Summary
- [42cursus - Libft](#42cursus---libft)
- [Summary](#summary)
- [Description:](#description)
- [Makefile](#makefile)
- [Libc Functions](#libc-functions)
- [Additional Functions](#additional-functions)
- [Linked Lists](#linked-lists)

---

# Description:

Creating our very own c library called Libft.
In this library we are recreating many functions from the standard C library, as well as some utility functions that we will use throughout the cursus

---

# Makefile

| Command     | Action                                      |
| ----------- | ------------------------------------------- |
| make        | Compile .c files and create libft.a         |
| make clean  | Delete .o files                             |
| make fclean | Delete .o files and libft.a                 |
| make re     | Deletes .o files and libft.a and recompiles |

---

# Libc Functions
 - ft_isalpha [(man)](https://man7.org/linux/man-pages/man3/isspace.3.html)
 - ft_isdigit [(man)](https://man7.org/linux/man-pages/man3/isspace.3.html)
 - ft_isalnum [(man)](https://man7.org/linux/man-pages/man3/isspace.3.html)
 - ft_isascii [(man)](https://man7.org/linux/man-pages/man3/isspace.3.html)
 - ft_isprint [(man)](https://man7.org/linux/man-pages/man3/isspace.3.html)
 - ft_strlen  [(man)](https://man7.org/linux/man-pages/man3/strlen.3.html) 
 - ft_memset  [(man)](https://man7.org/linux/man-pages/man3/memset.3.html)
 - ft_bzero   [(man)](https://man7.org/linux/man-pages/man3/bzero.3.html)
 - ft_memcpy  [(man)](https://man7.org/linux/man-pages/man3/memcpy.3.html)
 - ft_memmove [(man)](https://man7.org/linux/man-pages/man3/memmove.3.html)
 - ft_strlcpy [(man)](https://man7.org/linux/man-pages/man7/string_copying.7.html)
 - ft_strlcat [(man)](https://man7.org/linux/man-pages/man7/string_copying.7.html)
 - ft_toupper [(man)](https://man7.org/linux/man-pages/man3/toupper.3.html)
 - ft_tolower [(man)](https://man7.org/linux/man-pages/man3/toupper.3.html)
 - ft_strchr  [(man)](https://man7.org/linux/man-pages/man3/strchr.3.html)
 - ft_strrchr [(man)](https://man7.org/linux/man-pages/man3/strchr.3.html)
 - ft_strncmp [(man)](https://man7.org/linux/man-pages/man3/strncmp.3p.html)
 - ft_memchr  [(man)](https://man7.org/linux/man-pages/man3/memchr.3.html)
 - ft_memcmp  [(man)](https://man7.org/linux/man-pages/man3/memcmp.3.html)
 - ft_strnstr [(man)](https://man.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3)
 - ft_atoi    [(man)](https://man7.org/linux/man-pages/man3/atoi.3.html)
 - ft_calloc  [(man)](https://man7.org/linux/man-pages/man3/calloc.3p.html)
 - ft_strdup  [(man)](https://man7.org/linux/man-pages/man3/strdup.3.html)

---

# Additional Functions

| Function        | Prototype                                                         | Description                                                                                             |
| --------------- | ----------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| `ft_substr`     | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates and returns a substring from string `s`, starting at index `start` with maximum length `len`. |
| `ft_strjoin`    | `char *ft_strjoin(char const *s1, char const *s2);`               | Allocates and returns a new string resulting from the concatenation of `s1` and `s2`.                   |
| `ft_strtrim`    | `char *ft_strtrim(char const *s1, char const *set);`              | Allocates and returns a copy of `s1` with characters from `set` removed from the beginning and end.     |
| `ft_split`      | `char **ft_split(char const *s, char c);`                         | Splits string `s` using character `c` as a delimiter and returns a NULL-terminated array of strings.    |
| `ft_itoa`       | `char *ft_itoa(int n);`                                           | Allocates and returns a string representing the integer `n`.                                            |
| `ft_strmapi`    | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies function `f` to each character of `s` and returns a new string with the results.                |
| `ft_striteri`   | `void ft_striteri(char *s, void (*f)(unsigned int, char *));`     | Applies function `f` to each character of `s` by reference.                                             |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);`                             | Outputs character `c` to the given file descriptor.                                                     |
| `ft_putstr_fd`  | `void ft_putstr_fd(char *s, int fd);`                             | Outputs string `s` to the given file descriptor.                                                        |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);`                            | Outputs string `s` followed by a newline to the given file descriptor.                                  |
| `ft_putnbr_fd`  | `void ft_putnbr_fd(int n, int fd);`                               | Outputs integer `n` to the given file descriptor.                                                       |

# Linked Lists

The following functions manipulate linked lists using the structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```
| Function          | Prototype                                                                  | Description                                                                                                                                                                                                                                  |
| ----------------- | -------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `ft_lstnew`       | `t_list *ft_lstnew(void *content);`                                        | Allocates and returns a new node with `content` initialized and `next` set to `NULL`.                                                                                                                                                        |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);`                         | Adds the node `new` at the beginning of the list.                                                                                                                                                                                            |
| `ft_lstsize`      | `int ft_lstsize(t_list *lst);`                                             | Returns the number of nodes in the list.                                                                                                                                                                                                     |
| `ft_lstlast`      | `t_list *ft_lstlast(t_list *lst);`                                         | Returns the last node of the list.                                                                                                                                                                                                           |
| `ft_lstadd_back`  | `void ft_lstadd_back(t_list **lst, t_list *new);`                          | Adds the node `new` at the end of the list.                                                                                                                                                                                                  |
| `ft_lstdelone`    | `void ft_lstdelone(t_list *lst, void (*del)(void *));`                     | Frees the content of a node using `del` and then frees the node itself.                                                                                                                                                                      |
| `ft_lstclear`     | `void ft_lstclear(t_list **lst, void (*del)(void *));`                     | Deletes and frees all nodes of the list, then sets the list pointer to `NULL`.                                                                                                                                                               |
| `ft_lstiter`      | `void ft_lstiter(t_list *lst, void (*f)(void *));`                         | Iterates through the `lst` and applies the function `f` to the content of each node                                                                                                                                                          |
| `ft_lstmap`       | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Iterates through the list `lst`, applies the function `f` to each node's content, and creates a new list resulting of the successive applications of the function `f`. The `del` function is used to delete the content of a node if needed. |
