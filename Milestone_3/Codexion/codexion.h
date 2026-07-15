/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:21:21 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/07/15 15:24:30 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H

# define CODEXION_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_coders;
	long long		time_to_burnout;
	long long		time_to_compile;
	long long		time_to_debug;
	long long		time_to_refactor;
	int				number_of_compiles_required;
	long long		dongle_cooldown;
	char			*scheduler;
	int				simulation_over;
	long long 		start_time;
	int*			dongles;
	pthread_mutex_t	mutex_data;
	pthread_cond_t	condition;
	pthread_t		thread_id;
}			   t_data;

typedef struct s_thread_data
{
	int				id;
	long long		last_compile_start;
	int				times_compiled;
	pthread_t		thread_id;
	pthread_mutex_t	mutex_coder;
	t_data			*data;
}			   t_thread_data;

long long	get_time();
int	num_check(char *num);

#endif
