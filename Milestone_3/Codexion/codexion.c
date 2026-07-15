/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaylor- <dtaylor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:57:08 by dtaylor-          #+#    #+#             */
/*   Updated: 2026/07/15 17:19:38 by dtaylor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void* routine(void* arg)
{
	t_thread_data	*coder;
	t_data			*data;
	long long		time;
	int				i;
	int				left_dongle;
    int				right_dongle;

	coder = (t_thread_data*) arg;
	data = coder->data;
	left_dongle = coder->id - 1;
	right_dongle = coder->id % data->num_coders;
	i = 0;
	while (1)
	{
		while (1)
        {
            pthread_mutex_lock(&data->mutex_data);
            if (data->simulation_over)
            {
                pthread_mutex_unlock(&data->mutex_data);
                return (NULL); 
            }

            if (data->dongles[left_dongle] == -1 && data->dongles[right_dongle] == -1)
            {
                data->dongles[left_dongle] = coder->id;
                data->dongles[right_dongle] = coder->id;
                pthread_mutex_unlock(&data->mutex_data);
                break;
            }

            pthread_cond_wait(&data->condition, &data->mutex_data);
            pthread_mutex_unlock(&data->mutex_data);
        }

		pthread_mutex_lock(&data->mutex_data);
		if (data->simulation_over)
		{
			pthread_mutex_unlock(&data->mutex_data);
			break;
		}
		if (coder->times_compiled > data->number_of_compiles_required)
		{
			pthread_mutex_unlock(&data->mutex_data);
			break;
		}
		time = get_time() - data->start_time;
		printf("%lld %d is compiling\n", time, coder->id);
		pthread_mutex_unlock(&data->mutex_data);

		pthread_mutex_lock(&coder->mutex_coder);
		coder->last_compile_start = get_time();
		coder->times_compiled++;
		pthread_mutex_unlock(&coder->mutex_coder);

		usleep(data->time_to_compile * 1000);

		pthread_mutex_lock(&data->mutex_data);
		if (data->simulation_over)
		{
			pthread_mutex_unlock(&data->mutex_data);
			break;
		}
		time = get_time() - data->start_time;
		printf("%lld %d is debugging\n", time, coder->id);
		pthread_mutex_unlock(&data->mutex_data);

		usleep(data->time_to_debug * 1000);

		pthread_mutex_lock(&data->mutex_data);
		if (data->simulation_over)
		{
			pthread_mutex_unlock(&data->mutex_data);
			break;
		}
		time = get_time() - data->start_time;
		printf("%lld %d is refactoring\n", time, coder->id);
		pthread_mutex_unlock(&data->mutex_data);

		pthread_mutex_lock(&data->mutex_data);
		data->dongles[left_dongle] = -1;
		data->dongles[right_dongle] = -1;
		pthread_mutex_unlock(&data->mutex_data);

		usleep(data->time_to_refactor * 1000);
	}
	return (NULL);
}

void* monitor(void* arg)
{
	t_data			*data;
	t_thread_data	*coders;
	int				i;
	int				j;
	long long		current_time;
	int				threads_done;

	coders = (t_thread_data*) arg;
	data = coders[0].data;

	while (1)
	{
		j = 0;
		threads_done = 0;
		pthread_mutex_lock(&data->mutex_data);
		while (j < data->num_coders)
		{
			if (coders[j].times_compiled > data->number_of_compiles_required)
				threads_done++;
			j++;
		}
		if (threads_done == data->num_coders)
		{
			data->simulation_over = 1;
			pthread_cond_broadcast(&data->condition);
			printf("Ended due to all coders compiling\n");
			pthread_mutex_unlock(&data->mutex_data);
			return (NULL);
		}
		pthread_mutex_unlock(&data->mutex_data);
		i = 0;
		while (i < data->num_coders)
		{
			pthread_mutex_lock(&coders[i].mutex_coder);
			current_time = get_time();

			if (current_time - coders[i].last_compile_start >= data->time_to_burnout)
			{

				pthread_mutex_lock(&data->mutex_data);
				data->simulation_over = 1;
				pthread_cond_broadcast(&data->condition);
				pthread_mutex_unlock(&data->mutex_data);
				
				pthread_mutex_unlock(&coders[i].mutex_coder);
				current_time = get_time() - data->start_time;
				printf("%lld %d burned out\n", current_time, coders[i].id);
				return (NULL);
			}
			pthread_mutex_unlock(&coders[i].mutex_coder);
			i++;
		}
		usleep(2000); 
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
	(*data) -> dongles = malloc((*data) -> num_coders * sizeof(int) + 1);
	memset((*data) -> dongles, -1, (*data) -> num_coders * sizeof(int));
	(*data) -> dongles[(*data)->num_coders] = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_thread_data	*coders;
	t_data			*data;
	long long		start_time;
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
	pthread_mutex_init(&data->mutex_data, NULL);
	pthread_cond_init(&data->condition, NULL);
	data -> start_time = start_time;
	while (i < data -> num_coders)
	{
		coders[i].id = i + 1;
		coders[i].data = data;
		coders[i].last_compile_start = 0;
		coders[i].times_compiled = 0;
		pthread_mutex_init(&coders[i].mutex_coder, NULL);
		i++;
	}
	if (pthread_create(&data->thread_id, NULL, &monitor, (void *) coders) != 0)
	{
		printf("Failed to create thread");
		return (1);
	}
	i = 0;
	while (i < data -> num_coders)
	{
		if (pthread_create(&coders[i].thread_id, NULL, &routine, &coders[i]) != 0)
		{
			printf("Failed to create coder thread");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data -> num_coders)
	{
		pthread_join(coders[i].thread_id, NULL);
		i++;
	}
	pthread_join(data->thread_id, NULL);
	i = 0;
	while (i < data -> num_coders)
	{
		pthread_mutex_destroy(&coders[i].mutex_coder);
		i++;
	}
	pthread_cond_destroy(&data->condition);
	pthread_mutex_destroy(&data->mutex_data);
	free(data);
	return (0);
}


// For only one coder burnout must happen, not holding two dongles!!
