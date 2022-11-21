/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:25:54 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 05:34:02 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	display(t_philo *philo, char *arg)
{
	if (check_death(philo))
		return (0);
	printf("%i %i %s\n", get_time() - philo->time_ref, philo->id, arg);
	return (1);
}

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_usleep(int time, t_philo *philo)
{
	int	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (check_death(philo))
			return ;
		usleep(500);
	}
}
