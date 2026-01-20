/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:20:16 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 14:44:05 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

/*void	ft_del(void *del)
{
	free(del);
}

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*temp;

	head = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	head -> content = strdup("1");
	head -> next = third;
	second -> content = strdup("2");
	second -> next = third;
	third -> content = strdup("3");
	third -> next = NULL;
	ft_lstdelone(second, ft_del);
	temp = head;
	while (temp != NULL)
	{
		printf("%s -> ",(char *) temp -> content);
		temp = temp -> next;
	}
	return (0);
}*/