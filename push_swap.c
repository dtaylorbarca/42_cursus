/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:06 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/13 17:28:02 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bench_presence(int argc, char **argv, t_count **count_list)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "--bench", ft_strlen("--bench")) == 0
			&& !argv[i][ft_strlen("--bench")])
		{
			if (argc < 3)
			{
				free(count_list);
				return (0);
			}
			if ((*count_list)->bench_active == 0)
				(*count_list)-> bench_active = 1;
			else
				return (0);
		}
		i++;
	}
}

void	push_swap(int argc, char **argv)
{
	t_count	*count_list;

	if (argc < 2)
		return (0);
	count_list = malloc(sizeof(t_count));
	if (!count_list)
		return ;
	initialize_list(&count_list);
	if (!bench_presence)
		return ;
	if (ft_strncmp(argv[1], "--bench", ft_strlen("--bench")) == 0
		&& !argv[1][ft_strlen("--bench")])
	{
		if (argc < 3)
		{
			free(count_list);
			return (0);
		}
		count_list -> bench_active = 1;
		argv ++;
	}
	arg_control(argv, &count_list);
	free(count_list);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc, argv);
	return (0);
}
