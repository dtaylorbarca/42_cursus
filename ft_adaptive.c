/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvillarr <lvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:34:59 by lvillarr          #+#    #+#             */
/*   Updated: 2026/03/09 20:35:01 by lvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_compute_disorder(t_list *stack)
{
	int		mistakes;
	float	total_pairs;
	t_list	*temp;
	t_list	*next_temp;

	if (!stack || !stack->next)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	temp = stack;
	next_temp = stack->next;
	while (temp->next != NULL)
	{
		if ((temp->nb) > (next_temp->nb))
			mistakes += 1;
		total_pairs += 1;
		temp = temp->next;
		next_temp = next_temp->next;
	}
	return ((float) mistakes / total_pairs);
}

void	ft_adaptive(t_list **stack_a, t_count **count_list)
{
	if (0.0 < (*count_list)->disorder && (*count_list)->disorder < 0.2)
		ft_simple(stack_a, count_list);
	else if (0.2 <= (*count_list)->disorder && (*count_list)->disorder <= 0.5)
		ft_medium(stack_a, count_list);
	else if (0.5 < (*count_list)->disorder && (*count_list)->disorder <= 1.0)
		ft_complex(stack_a, count_list);
	else if ((*count_list)->disorder == 0.0)
		return ;
	else
		write (2, "Error\n", 6);
}
