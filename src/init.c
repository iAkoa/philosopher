/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:01:27 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 05:36:43 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->death_meal, NULL);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
}

int	initialize_data(t_data *data, int ac, char **av)
{
	if (ac != 6 && ac != 5)
		return (-1);
	data->philo_death = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->nb_philo == -1 || data->time_to_die == -1
		|| data->time_to_eat == -1 || data->time_to_sleep == -1)
		return (-1);
	data->meals_nb = -1;
	if (ac == 6)
	{
		data->meals_nb = ft_atoi(av[5]);
		if (data->meals_nb == 0)
			data->meals_nb = -2;
		if (data->meals_nb == -1)
			return (-1);
	}
	ft_init_mutex(data);
	return (1);
}
