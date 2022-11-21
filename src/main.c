/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:24:39 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 05:56:25 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

static void	clean_data(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->death_meal);
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&data->fork[i]);
	i = -1;
	free(data->fork);
}

static void	clean_all(t_data *data, t_philo **philo_array)
{
	mutex_join(data, philo_array);
	detach_thread(data, philo_array);
	destroy_mutex(data, philo_array);
	free_all(data, philo_array);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	**philo_array;

	philo_array = NULL;
	if (!check_arg(ac, av))
		return (0);
	if (initialize_data(&data, ac, av) == -1)
	{
		if (data.meals_nb == -1)
			return (0);
		return (printf("wrong argument !\n"));
	}
	if (data.nb_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("%i 1 is died\n", data.time_to_die);
		clean_data(&data);
		return (0);
	}
	philo_array = create_philo_array(&data, philo_array);
	while_check_stop_thread(&data, philo_array);
	clean_all(&data, philo_array);
	return (0);
}
