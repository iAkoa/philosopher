/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:24:39 by pat               #+#    #+#             */
/*   Updated: 2022/11/11 03:58:13 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int main (int ac, char **av)
{
	t_data data;
	initialize_data(&data, ac, av);
	printf("nb_philo = %i\n", data.nb_philo);
	printf("time_to_die = %i\n", data.time_to_die);
	printf("time_to_eat = %i\n", data.time_to_eat);
	printf("time_to_sleep = %i\n", data.time_to_sleep);
	t_philo **philo_array = NULL;
	philo_array = create_philo_array(&data, philo_array);
	mutex_join(&data, philo_array);
}