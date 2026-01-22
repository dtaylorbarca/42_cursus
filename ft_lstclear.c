/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:35:56 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:04:42 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
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

