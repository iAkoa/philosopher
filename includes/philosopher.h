#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

# define ERROR 2;
# define TRUE 1;
# define FALSE 0;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_nb;
	pthread_mutex_t	mutex;
}			t_data;
typedef struct s_philo
{
	int				id;
	int				fork;
	t_data			*data;
	pthread_t		thread;
}			t_philo;

int		initialize_data(t_data *data, int ac,char **av);
int		ft_atoi(const char *nbr);
void	*create_philo(t_data *data, t_philo **philo_array, int id);
t_philo	**create_philo_array(t_data *data, t_philo **philo_array);
void	*routine(void *arg);
int		mutex_join(t_data *data, t_philo **philo_array);

#endif