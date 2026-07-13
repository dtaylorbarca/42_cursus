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
	pthread_mutex_t	mutex;
	pthread_cond_t	condition;
}			   t_data;

typedef struct s_thread_data
{
	int				id;
	long long 		start_time;
	pthread_t		thread_id;
	t_data			*data;
}			   t_thread_data;

long long	get_time();
int	num_check(char *num);

#endif
