/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:08:01 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/19 17:04:22 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ltsadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	lst = malloc(sizeof(t_list));

	new->content = "Hello";
	new->next = NULL;

	lst->content = "Dylan";
	lst->next = NULL;

	// BEFORE
	printf("Before:\n");
	tmp = lst;
	while (tmp)
	{
		printf("%s -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");

	ft_ltsadd_front(&lst, new);

	// AFTER
	printf("\nAfter:\n");
	tmp = lst;
	while (tmp)
	{
		printf("%s -> ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");

	return (0);
}
