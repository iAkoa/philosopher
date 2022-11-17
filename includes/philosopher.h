#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>


typedef struct s_data
{
	int				nb_philo;
	int				philo_dead;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_ref;
	int				meals_nb;
	pthread_mutex_t	mutex_dead;
}			t_data;
typedef struct s_philo
{
	int				id;
	int				fork;
	int				time_start;
	int				time_finish;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	mutex_fork;
}			t_philo;

int				initialize_data(t_data *data, int ac,char **av);
int				ft_atoi(const char *nbr);
void			*create_philo(t_data *data, t_philo **philo_array, int id);
t_philo			**create_philo_array(t_data *data, t_philo **philo_array);
void			*routine(void *arg);
int				mutex_join(t_data *data, t_philo **philo_array);
void			display(t_philo *philo, char *arg);
int				check_dead(t_philo *philo);
int				get_time();

#endif