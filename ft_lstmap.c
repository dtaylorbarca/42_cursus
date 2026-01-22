/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:14:44 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:14:53 by dtaylor-         ###   ########.fr       */
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
		if (f)
			new_node = ft_lstnew(f(lst -> content));
		else
			new_node = ft_lstnew(lst -> content);
		if (!new_node)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_node);
		lst = lst -> next;
	}
	return (new_list);
}
