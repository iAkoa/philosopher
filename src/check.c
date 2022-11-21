/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:30:50 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 05:35:09 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	check_meal(t_philo *philo)
{	
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->meals == philo->data->meals_nb)
	{
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_meal);
	if (philo->data->philo_death == 1)
	{
		pthread_mutex_unlock(&philo->data->death_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_meal);
	return (0);
}

int	while_check_stop_thread(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (data->philo_death == 0)
	{
		if (i < data->nb_philo)
			i = 0;
		pthread_mutex_lock(&philo[i]->last_meal_mutex);
		if (get_time() - philo[i]->last_meal >= data->time_to_die)
		{
			pthread_mutex_lock(&philo[i]->data->death_meal);
			data->philo_death = 1;
			pthread_mutex_lock(&philo[i]->meal_mutex);
			if (data->philo_death && data->meals_nb != philo[i]->meals)
				printf("%i %i %s\n", get_time()
					- philo[i]->time_ref, philo[i]->id, " died");
			pthread_mutex_unlock(&philo[i]->meal_mutex);
			pthread_mutex_unlock(&philo[i]->data->death_meal);
			pthread_mutex_unlock(&philo[i]->last_meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo[i]->last_meal_mutex);
		i++;
	}
	return (0);
}
