/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 04:30:44 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 05:36:09 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	detach_thread(t_data *data, t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_detach(philo[i]->philo);
	return (0);
}

int	destroy_mutex(t_data *data, t_philo **philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->death_meal);
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&data->fork[i]);
	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_destroy(&philo[i]->last_meal_mutex);
	}
	return (0);
}

int	free_all(t_data *data, t_philo **philo)
{
	int	i;

	i = -1;
	free(data->fork);
	while (++i < data->nb_philo)
		free(philo[i]);
	free(philo);
	return (0);
}
