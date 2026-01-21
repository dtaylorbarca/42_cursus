/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:59:27 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 18:05:35 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}

/*int	main(void)
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
}*/
