/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:59:27 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/16 17:19:36 by dtaylor-         ###   ########.fr       */
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
	int		size;
	int		count;

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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = ft_lstlast(first);
	last -> next = new;
}

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list  *temp;
	t_list	*new;

	head = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	new = (t_list *) malloc(sizeof(t_list));
	head -> content = "1";
	head -> next = second;
	second -> content = "2";
	second -> next = third;
	third -> content = "3";
	third -> next = NULL;
	new -> content = "4";
	new -> next = NULL;
	ft_lstadd_back(&head, new);
	temp = head;
	while (temp != NULL)
	{
		printf("%s -> ",(char *) temp -> content);
		temp = temp -> next;
	}
	return (0);
}

