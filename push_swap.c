/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvillarr <lvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:35:26 by lvillarr          #+#    #+#             */
/*   Updated: 2026/03/10 12:02:19 by lvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_count	*count_list;

	if (argc < 1)
		return (0);
	count_list = malloc(sizeof(t_count));
	if (!count_list)
		return (0);
	initialize_list(&count_list);
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
	if (argc <= 1)
		return (-1);
	push_swap(argc, argv);
	return (0);
}
