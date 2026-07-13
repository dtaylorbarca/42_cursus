/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:57:08 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/07/13 18:41:37 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void*	routine(void* arg)
{
	t_thread_data	*coder;
	t_data			*data;
	long long		time;

	coder = (t_thread_data*) arg;
	data = coder->data;
	while (1)
	{
		pthread_mutex_lock(&data -> mutex_data);
		time = get_time() - coder -> start_time;
		printf("%lld %d is compiling\n", time, coder -> id);
		usleep(data->time_to_compile * 1000);
		pthread_mutex_unlock(&data -> mutex_data);

		pthread_mutex_lock(&data -> mutex_data);
		time = get_time() - coder -> start_time;
		printf("%lld %d is debugging\n", time, coder -> id);
		usleep(data->time_to_debug * 1000);
		pthread_mutex_unlock(&data -> mutex_data);

		pthread_mutex_lock(&data -> mutex_data);
		time = get_time() - coder -> start_time;
		printf("%lld %d is refactoring\n", time, coder -> id);
		usleep(data->time_to_refactor * 1000);
		pthread_mutex_unlock(&data -> mutex_data);

		pthread_mutex_lock(&data -> mutex_data);
		// while (!data -> simulation_over)
		// {
		// 	pthread_cond_wait(&data -> condition,
		// 		&data -> mutex_data);
		// }
		if (data->simulation_over)
		{
			pthread_mutex_unlock(&data->mutex_data);
			break ;
		}
		pthread_mutex_unlock(&data->mutex_data);
	}
	return (NULL);
}

void*	monitor(void* arg)
{
	t_thread_data	*coders;
	t_data	*data;
	long long start_time;

	data = (t_data*) arg;
	start_time = get_time();
	while (1)
	{
		pthread_mutex_lock(
		pthread_mutex_lock(&data -> mutex_data);
		data -> simulation_over = 1;
		pthread_cond_broadcast(&data->condition);
		pthread_mutex_unlock(&data -> mutex_data);
	}

	return (NULL);
}

int	data_setup(t_data ** data, char **argv)
{
	int	i;

	i = 1;
	while (i < 8)
	{
		if (!num_check(argv[i]))
			return (0);
		i++;
	}
	if (strcmp("fifo", argv[8]) && strcmp("edf", argv[8]))
		return (0);
	(*data) -> num_coders = num_check(argv[1]);
	(*data) -> time_to_burnout = num_check(argv[2]);
	(*data) -> time_to_compile = num_check(argv[3]);
	(*data) -> time_to_debug = num_check(argv[4]);
	(*data) -> time_to_refactor = num_check(argv[5]);
	(*data) -> number_of_compiles_required = num_check(argv[6]);
	(*data) -> dongle_cooldown = num_check(argv[7]);
	(*data) -> scheduler = argv[8];
	(*data) -> simulation_over = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t mutex;
	pthread_cond_t	cond;
	t_thread_data 	*coders;
	t_data  		*data;
	long long 		start_time;
	int				i;

	start_time = get_time();
	if (argc != 9)
	{
		printf("8 arguments must be provided");
		return (1);
	}
    data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));
	if (!data_setup(&data, argv))
	{
		printf("Syntax error");
		return (1);
	}
	i = 0;
	coders = (t_thread_data *) malloc((data -> num_coders) * sizeof(t_thread_data));
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	data -> mutex = mutex;
	data -> condition = cond;
	while (i < data -> num_coders)
	{
		coders[i].id = i + 1;
		coders[i].data = data;
		coders[i].start_time = start_time;
		if (pthread_create(&coders[i].thread_id, NULL, &routine, &coders[i]) != 0)
		{
			printf("Failed to create thread");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data -> num_coders)
	{
		pthread_join(coders[i].thread_id, NULL);
		printf("Coder %d has finished\n", coders[i].id);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	free(data);
	return (0);
}
