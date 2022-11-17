/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:25:54 by pat               #+#    #+#             */
/*   Updated: 2022/11/16 08:37:21 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void display(t_philo *philo, char *arg)
{
	printf("%i ", timer(philo) - philo->data->time_ref);
	printf("%i ", philo->id);
	printf("%s\n", arg);
}

int get_time(t_philo *philo)
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	philo->time_start = current_time.tv_sec * 1000 + current_time.tv_usec/ 1000;
	return(1);
}

// struct timeval time_end(struct timeval time_start, t_philo *philo)
// {
// 	struct timeval current_time;
// 	gettimeofday(&current_time, NULL);
// 	philo->time_start = current_time.tv_sec;
// 	return (current_time);
// }