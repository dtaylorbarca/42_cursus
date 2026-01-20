/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:44:30 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 14:44:43 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
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
}*/