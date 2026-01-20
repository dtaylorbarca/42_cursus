/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:23:48 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/20 14:45:17 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}

/*int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	head = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	head -> content = "1";
	head -> next = second;
	second -> content = "2";
	second -> next = third;
	third -> content = "3";
	third -> next = NULL;
	printf("The length of the list is: %d", ft_lstsize(head));
	return (0);
}*/
