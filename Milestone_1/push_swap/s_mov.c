/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:25 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 16:15:00 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_move(t_list **stack, t_count **count_list)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
	(*count_list)->sa += 1;
	write(1, "sa\n", 3);
}

void	sb_move(t_list **stack, t_count **count_list)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
	(*count_list)->sb += 1;
	write(1, "sb\n", 3);
}

void	ss_move(t_list **stack_a, t_list **stack_b, t_count **count_list)
{
	sa_move(stack_a, count_list);
	sb_move(stack_b, count_list);
	(*count_list)->sa -= 1;
	(*count_list)->sb -= 1;
	(*count_list)->ss += 1;
	write(1, "ss\n", 3);
}
