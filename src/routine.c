/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:39:33 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 06:07:01 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*routine_eat(t_philo *philo)
{
	if (check_meal(philo))
		return (NULL);
	pthread_mutex_lock(philo->fork_left);
	if (!display(philo, "has taken a fork"))
		return (NULL);
	pthread_mutex_lock(philo->fork_right);
	if (!display(philo, "has taken a fork"))
		return (NULL);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (!display(philo, "is eating"))
		return (NULL);
	if (philo->data->meals_nb != -1 && philo->data->meals_nb != -2)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		philo->meals++;
		pthread_mutex_unlock(&philo->meal_mutex);
	}
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (philo);
}

void	*routine_sleep(t_philo *philo)
{
	ft_usleep(philo->data->time_to_sleep, philo);
	if (!display(philo, "is sleeping"))
		return (NULL);
	return (philo);
}

void	*routine_think(t_philo *philo)
{
	if (!display(philo, "is thinking"))
		return (NULL);
	return (philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->time_ref = get_time();
	if (philo->id % 2 == 0)
		ft_usleep((philo->data->time_to_eat) / 4, philo);
	while (1)
	{
		if (!routine_eat(philo))
			return (NULL);
		if (!routine_sleep(philo))
			return (NULL);
		if (!routine_think(philo))
			return (NULL);
	}
	return (NULL);
}
