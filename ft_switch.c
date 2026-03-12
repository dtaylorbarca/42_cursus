/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:44:57 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/12 16:43:17 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	type_algorithm(char *argv)
{
	if (ft_strncmp(argv, "--simple", ft_strlen("--simple")) == 0
		&& !argv[ft_strlen("--simple")])
		return (1);
	else if (ft_strncmp(argv, "--medium", ft_strlen("--medium")) == 0
		&& !argv[ft_strlen("--medium")])
		return (2);
	else if (ft_strncmp(argv, "--complex", ft_strlen("--complex")) == 0
		&& !argv[ft_strlen("--complex")])
		return (3);
	else if (ft_strncmp(argv, "--adaptive", ft_strlen("--adaptive")) == 0
		&& !argv[ft_strlen("--adaptive")])
		return (4);
	else
		return (0);
}

int	ft_switch(char *strat, t_list *stack_a, t_count **count_list)
{
	int	type;

	type = type_algorithm(strat);
	if (type == 1)
		ft_simple(&stack_a, count_list);
	else if (type == 2)
		ft_medium(&stack_a, count_list);
	else if (type == 3)
		ft_complex(&stack_a, count_list);
	else if (type == 4)
		ft_adaptive(&stack_a, count_list);
	else
		write(2, "Error\n", 6);
	return (type);
}
