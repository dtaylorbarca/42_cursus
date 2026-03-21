/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:33 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/13 15:53:08 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **a, t_count **count_list)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->nb;
	y = (*a)->next->nb;
	z = (*a)->next->next->nb;
	if (x > y && y > z)
	{
		sa_move(a, count_list);
		rra_move(a, count_list);
	}
	else if (x < y && y > z && x < z)
	{
		sa_move(a, count_list);
		ra_move(a, count_list);
	}
	else if (x > y && y < z && x > z)
		ra_move(a, count_list);
	else if (x < y && y > z && x > z)
		rra_move(a, count_list);
	else if (x > y && y < z && x < z)
		sa_move(a, count_list);
}

static void	sort_2(t_list **a, t_count **count_list)
{
	if ((*a)->nb > (*a)->next->nb)
		sa_move(a, count_list);
}

void	tiny_sort(t_list **stack_a, t_count **count_list)
{
	int		size;

	size = stack_size(*stack_a);
	if (size > 3 && size < 6)
		ft_simple(stack_a, count_list);
	else if (size == 3)
		sort_3(stack_a, count_list);
	else if (size == 2)
		sort_2(stack_a, count_list);
}
