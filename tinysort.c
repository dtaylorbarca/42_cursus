/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:33 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 21:07:56 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **a, t_count **count_list)
{
	if ((*a)->nb > (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
	{
		ra_move(a, count_list);
		if (ft_compute_disorder(*a) != 0.00)
			sa_move(a, count_list);
	}
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb)
	{
		sa_move(a, count_list);
		ra_move(a, count_list);
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb)
	{
		sa_move(a, count_list);
		if (ft_compute_disorder(*a) != 0.00)
			rra_move(a, count_list);
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
	{
		sa_move(a, count_list);
		if (ft_compute_disorder(*a) != 0.00)
			rra_move(a, count_list);
	}
}

static void	sort_2(t_list **stack_a, t_count **count_list)
{
	if ((*count_list)->disorder == 1.00)
		sa_move(stack_a, count_list);
}

void	tiny_sort(t_list **stack_a, t_count **count_list)
{
	int		size;
	t_list	*tmp;

	tmp = NULL;
	size = stack_size(*stack_a);
	if (size > 3 && size < 6)
		ft_simple(stack_a, count_list);
	else if (size == 3)
		sort_3(stack_a, count_list);
	else if (size == 2)
		sort_2(stack_a, count_list);
}
