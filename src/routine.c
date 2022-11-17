/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:39:33 by pat               #+#    #+#             */
/*   Updated: 2022/11/16 08:39:18 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"
void *routine_eat(t_philo *philo)
{
	if (check_dead(philo))
		return (NULL);
	pthread_mutex_lock(&philo[-1].mutex_fork);
	if(philo[-1].fork)
	{
		pthread_mutex_lock(&philo->mutex_fork);
		philo->fork++;
		pthread_mutex_unlock(&philo->mutex_fork);
		get_time();
		display(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_unlock(&philo[-1].mutex_fork);
		pthread_mutex_unlock(&philo->mutex_fork);
		return(philo);
	}
	pthread_mutex_unlock(&philo->mutex_fork);
	if (philo->fork == 2)
	{
		display(philo,"is eating");
		pthread_mutex_unlock(&philo->mutex_fork);
		get_time();
		return(philo);
	}
	pthread_mutex_unlock(&philo->mutex_fork);
	return(philo);
}
void *routine_sleep(t_philo *philo)
{
	
	if (check_dead(philo))
		return (NULL);
	// ft_sleep(philo->data->time_to_sleep);
	// timer(philo);
	display(philo, "is sleeping!");
	return(philo);
}
void *routine_think(t_philo *philo)
{
	if (check_dead(philo))
		return (NULL);
	// timer(philo);
	display(philo, "is thinking!");
	return(philo);
}
void *routine(void *arg)
{
	t_philo *philo;
	philo = arg;
	int i = 0;
	philo->data->time_ref = get_time();
	while (1)
	{
		// printf("%i\n", philo->data->philo_dead);
		if(!routine_eat(philo))
			return(NULL);
		if(!routine_sleep(philo))
			return(NULL);
		if(!routine_think(philo))
			return(NULL);
			i++;
	}
	return(NULL);
}