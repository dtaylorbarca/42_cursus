/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:57:08 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/07/09 17:34:42 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <pthread.h>

int	num_check(char *num)
{
	int	i;
	int	number;

	i = 0;
	while (num[i])
	{
		if ('9' <= num ||  num <= '0')
			return (-1);
	}
	number = atoi(num);
	if (number < 1)
		return (-1);
	return (number);
}

int	main(int argc, char **argv)
{
	int		num_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;

	if (argc != 9)
	{
		printf("8 arguments must be provided");
		return (1);
	}
	num_coders = num_check(argv[1]);
	time_to_burnout = atoi(argv[2]);
	time_to_compile = atoi(argv[3]);
	time_to_debug = atoi(argv[4]);
	time_to_refactor = atoi(argv[5]);
	number_of_compiles_required = atoi(argv[6]);
	dongle_cooldown = atoi(argv[7]);
	if (strcmp("fifo", argv[8]) || strcmp("edf", argv[8]))
		scheduler = argv[8];
	else
	{
		printf("Scheduler must be either fifo (First In, First Out)"
			"or edf (Earliest Deadline First)");
		return (-1);
	}
	return (0);
}
