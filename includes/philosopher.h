/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:53:59 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 05:54:40 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	int				philo_death;
	int				meals_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*fork;
	pthread_mutex_t	death_meal;
}			t_data;
typedef struct s_philo
{
	int				id;
	int				time_ref;
	int				start_meal;
	int				last_meal;
	int				meals;
	t_data			*data;
	pthread_t		philo;
	pthread_mutex_t	test;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}			t_philo;

int		initialize_data(t_data *data, int ac, char **av);
int		ft_atoi(const char *nbr);
void	*create_philo(t_data *data, t_philo **philo_array, int id);
t_philo	**create_philo_array(t_data *data, t_philo **philo_array);
void	*routine(void *arg);
int		mutex_join(t_data *data, t_philo **philo_array);
int		display(t_philo *philo, char *arg);
int		while_check_stop_thread(t_data *data, t_philo **philo);
int		get_time(void);
void	ft_usleep(int time, t_philo *philo);
void	ft_init_mutex(t_data *data);
int		check_death(t_philo *philo);
int		check_meal(t_philo *philo);
int		detach_thread(t_data *data, t_philo **philo);
int		destroy_mutex(t_data *data, t_philo **philo);
int		free_all(t_data *data, t_philo **philo);
int		check_arg(int ac, char **arg);

#endif