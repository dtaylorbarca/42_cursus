/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:44:30 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/01/22 15:04:55 by dtaylor-         ###   ########.fr       */
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

