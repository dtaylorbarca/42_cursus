/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*holder;

	while ((*begin_list) && !cmp((*begin_list)->data, data_ref))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	temp = *begin_list;
	while (temp -> next != NULL)
	{
		if (!cmp(temp->next->data, data_ref))
		{
			holder = temp->next->next;
			free(temp->next);
			temp->next = holder;
		}
		else
			temp = temp->next;
	}
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_list.h"

// Sample comparison function (matches strcmp behavior)
int	cmp_strings(void *data, void *ref)
{
	return (strcmp((char *)data, (char *)ref));
}

// Helper to add nodes to the front of the list
void	push_front(t_list **list, void *data)
{
	t_list *new = malloc(sizeof(t_list));
	new->data = data;
	new->next = *list;
	*list = new;
}

int	main(void)
{
	t_list *list = NULL;

	push_front(&list, "World");
	push_front(&list, "Remove Me");
	push_front(&list, "Hello");
	push_front(&list, "Remove Me");

	printf("Before removal:\n");
	for (t_list *it = list; it; it = it->next)
		printf("%s -> ", (char *)it->data);
	printf("NULL\n");

	// Remove all nodes containing "Remove Me"
	ft_list_remove_if(&list, "Remove Me", cmp_strings);

	printf("\nAfter removal:\n");
	for (t_list *it = list; it; it = it->next)
		printf("%s -> ", (char *)it->data);
	printf("NULL\n");

	return (0);
}
