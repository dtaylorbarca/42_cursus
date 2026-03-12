/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:43:57 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 15:44:00 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	total_sum(t_count *count_list)
{
	int	total;

	total = 0;
	total += count_list->sa;
	total += count_list->sb;
	total += count_list->ss;
	total += count_list->pa;
	total += count_list->pb;
	total += count_list->ra;
	total += count_list->rb;
	total += count_list->rr;
	total += count_list->rra;
	total += count_list->rrb;
	total += count_list->rrr;
	return (total);
}

static void	select_adaptive(t_count *count_list)
{
	if (0.0 < count_list->disorder && count_list->disorder < 0.2)
		ft_printf("Adaptive / (O(n^2)\n");
	else if (0.2 <= count_list->disorder && count_list->disorder <= 0.5)
		ft_printf("Adaptive / O(n√n)\n");
	else if (0.5 < count_list->disorder && count_list->disorder <= 1.0)
		ft_printf("Adaptive / O(n log n)\n");
	else if (count_list->disorder == 0.0)
		return ;
	else
		write(2, "Error\n", 6);
}

void	benchmark(t_count *count_list, int type)
{
	int	x;
	int	y;
	int	mv;

	x = (int)(count_list->disorder * 100);
	y = (int)((count_list->disorder * 10000) - (x * 100));
	mv = total_sum(count_list);
	ft_printf("[bench] disorder:	%d.%d%%\n", x, y);
	ft_printf("[bench] strategy:	");
	if (type == 1)
		ft_printf("Simple / (O(n^2))\n");
	else if (type == 2)
		ft_printf("Medium / O(n√n)\n");
	else if (type == 3)
		ft_printf("Complex /  O(n log n)\n");
	else
		select_adaptive(count_list);
	ft_printf("[bench] total_ops:	%d\n", mv);
	ft_printf("[bench] sa:	%d	sb:	%d	ss:	%d pa:	%d	pb:	%d\n",
		count_list->sa, count_list->sb, count_list->ss, count_list -> pa,
		count_list ->pb);
	ft_printf("[bench] ra:	%d	rb:	%d	rr:	%d rra:	%d	rrb:	%d	",
		count_list->ra, count_list->rb, count_list->rr, count_list->rra,
		count_list->rrb);
	ft_printf("rrr:	%d\n", count_list->rrr);
}
