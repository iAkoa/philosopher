/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:39:33 by pat               #+#    #+#             */
/*   Updated: 2022/11/13 19:59:42 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"
void *routine_eat(t_philo *philo)
{
	displays(philo, "has taken a fork");
	displays(philo,"is eating");
}
void *routine_sleep(t_philo *philo)
{
	displays("is sleeping!");
}
void *routine_think(t_philo *philo)
{
	displays("is thinking!");
}
void *routine(void *arg)
{
	t_philo *philo;
	philo = arg;
	// printf("meeals_nb = %i\n", philo->data->meals_nb);
	while (1)
	{
		routine_eat(philo);
		routine_sleep(philo);
		routine_think(philo);
	}
	return(NULL);
}