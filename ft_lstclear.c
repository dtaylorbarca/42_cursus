/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:35:56 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 14:42:06 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_cont;
	t_list	*temp_node;

	if (!lst || !del)
		return ;
	temp_cont = *lst;
	while (temp_cont != NULL)
	{
		temp_node = temp_cont;
		del(temp_cont -> content);
		temp_cont = temp_cont -> next;
		free(temp_node);
	}
	*lst = NULL;
}

/*void    ft_del(void *del)
{
    free(del);
}

// Helper to create new nodes easily
t_list  *ft_lstnew(void *content)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new) return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

// --- The Testing Main ---

int main(void)
{
    t_list  *head;

    // 1. Setup: Create a list of 3 nodes with HEAP memory strings
    head = ft_lstnew(strdup("Node 1"));
    head->next = ft_lstnew(strdup("Node 2"));
    head->next->next = ft_lstnew(strdup("Node 3"));

    printf("--- Before ft_lstclear ---\n");
    t_list *temp = head;
    while (temp)
    {
        printf("Address: %p | Content: %s\n", (void *)temp, (char *)temp->content);
        temp = temp->next;
    }

    // 2. Execution: Clear the entire list
    // We pass &head because it's a t_list **
    ft_lstclear(&head, ft_del);

    // 3. Verification
    printf("\n--- After ft_lstclear ---\n");
    if (head == NULL)
        printf("Success: Head pointer is now NULL.\n");
    else
        printf("Error: Head pointer was not set to NULL!\n");

    return (0);
}*/