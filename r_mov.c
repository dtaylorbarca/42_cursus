/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_mov.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:15 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 15:45:16 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	ra_move(t_list **stack, t_count **count_list)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first -> next;
	(*stack)-> prev = NULL;
	last = ft_lstlast(*stack);
	last -> next = first;
	first -> prev = last;
	first -> next = NULL;
	(*count_list)->ra += 1;
	write(1, "ra\n", 3);
}

void	rb_move(t_list **stack, t_count **count_list)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first -> next;
	(*stack)-> prev = NULL;
	last = ft_lstlast(*stack);
	last -> next = first;
	first -> prev = last;
	first -> next = NULL;
	(*count_list)->rb += 1;
	write(1, "rb\n", 3);
}

void	rr_move(t_list **stack_a, t_list **stack_b, t_count **count_list)
{
	ra_move(stack_a, count_list);
	rb_move(stack_b, count_list);
	(*count_list)->ra -= 1;
	(*count_list)->rb -= 1;
	(*count_list)->rr += 1;
	write(1, "rr\n", 3);
}
