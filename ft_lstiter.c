/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:13:59 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/21 18:11:22 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		f(temp -> content);
		temp = temp -> next;
	}
}

/*// --- Test Mapping Function ---
// This function will be passed to ft_lstiter to modify the content
void    ft_uppercase_content(void *content)
{
    char *str = (char *)content;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

// --- Helpers for Setup ---
t_list  *ft_lstnew(void *content)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new) return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

// --- Main Testing Function ---
int main(void)
{
    t_list  *head;

    // 1. Create the list with lowercase strings on the heap
    head = ft_lstnew(strdup("apple"));
    head->next = ft_lstnew(strdup("banana"));
    head->next->next = ft_lstnew(strdup("cherry"));

    // 2. Display the list BEFORE iteration
    printf("Before ft_lstiter:\n");
    t_list *temp = head;
    while (temp)
    {
        printf("  - %s\n", (char *)temp->content);
        temp = temp->next;
    }

    // 3. RUN THE ITERATION
    // This will travel through the list and 
	run ft_uppercase_content on each node
    ft_lstiter(head, ft_uppercase_content);

    // 4. Display the list AFTER iteration
    printf("\nAfter ft_lstiter (Uppercase Conversion):\n");
    temp = head;
    while (temp)
    {
        printf("  - %s\n", (char *)temp->content);
        temp = temp->next;
    }

    // Clean up (good practice!)
    // Ideally use your ft_lstclear here
    return (0);
}*/