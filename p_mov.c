/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:02 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 15:45:03 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	pa_move(t_list **stack_a, t_list **stack_b, t_count **count_list)
{
	t_list	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	temp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = temp;
	*stack_a = temp;
	(*stack_a)->prev = NULL;
	(*count_list)->pa += 1;
	write(1, "pa\n", 3);
}

void	pb_move(t_list **stack_a, t_list **stack_b, t_count **count_list)
{
	t_list	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	temp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = temp;
	*stack_b = temp;
	(*stack_b)->prev = NULL;
	(*count_list)->pb += 1;
	write(1, "pb\n", 3);
}
