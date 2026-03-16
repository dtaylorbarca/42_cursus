/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:45:06 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/03/16 12:47:27 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_count	*count_list;

	if (argc < 2)
		return ;
	count_list = malloc(sizeof(t_count));
	if (!count_list)
		return ;
	initialize_list(&count_list);
	if (ft_strncmp(argv[1], "--bench", ft_strlen("--bench")) == 0
		&& !argv[1][ft_strlen("--bench")])
	{
		if (argc < 3)
		{
			free(count_list);
			return ;
		}
		count_list -> bench_active = 1;
		argv ++;
	}
	arg_control(argv, &count_list);
	free(count_list);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap(argc, argv);
	return (0);
}
