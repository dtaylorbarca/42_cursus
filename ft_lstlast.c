/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:44:30 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/16 16:54:59 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		temp = temp -> next;
		count ++;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;
	int	size;
	int	count;

	temp = lst;
	size = ft_lstsize(lst);
	count = 0;
	while (count + 1 < size)
	{
		temp = temp -> next;
		count ++;
	}
	return (temp);
}

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*node;

	head = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	head -> content = "1";
	head -> next = second;
	second -> content = "2";
	second -> next = third;
	third -> content = "3";
	third -> next = NULL;
	node = ft_lstlast(head);
	printf("The last node of the list is: %s\n", (char *) node -> content);
	return (0);
}

