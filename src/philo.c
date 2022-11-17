/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:02:04 by pat               #+#    #+#             */
/*   Updated: 2022/11/16 08:16:44 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int mutex_join(t_data *data, t_philo **philo_array)
{
	int	i;
	int err;
	
	i = -1;
	while (++i < data->nb_philo)
	{
		err = pthread_join(philo_array[i]->thread, NULL);
		if (err)
			return (-1);
	}
	return (0);
}

void *create_philo(t_data *data, t_philo **philo_array, int i)
{
	philo_array[i] = malloc(sizeof(t_philo) * 1);
	if (!philo_array[i])
		return (NULL);
	philo_array[i]->id = i + 1;
	philo_array[i]->data = data;
	pthread_mutex_init(&philo_array[i]->mutex_fork, NULL);
	pthread_create(&philo_array[i]->thread, NULL, &routine, philo_array[i]);
	return (philo_array[i]);
}

t_philo **create_philo_array(t_data *data, t_philo **philo_array)
{
	int	i;
	
	i = 0;
	philo_array = malloc(sizeof(t_philo *) * data->nb_philo);
	if (!philo_array)
		return NULL;
	printf("test\n");
	while (i < data->nb_philo)
	{
		printf("test\n");
		philo_array[i] = create_philo(data, philo_array, i);
		if (!philo_array[i])
			return(NULL);
		i++;
	}
	return (philo_array);
}