/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:14:44 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 12:44:29 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst -> content));
		if (!new_node)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_node);
		lst = lst -> next;
	}
	return (new_list);
}

/*void    *ft_uppercase_content(void *content)
{
    char *str = (char *)content;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
	return (str);
}

void    ft_del(void *del)
{
    free(del);
}

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*node;
	t_list	*temp;

	head = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	head -> content = strdup("hello");
	head -> next = second;
	second -> content = strdup("hola");
	second -> next = third;
	third -> content = strdup("bonjour");
	third -> next = NULL;
	node = ft_lstmap(head, ft_uppercase_content, ft_del);
	temp = node;
	while (temp != NULL)
	{
		printf("%s -> ",(char *) temp -> content);
	 	temp = temp -> next;
	}
	return (0);
}*/