/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:08:11 by pat               #+#    #+#             */
/*   Updated: 2022/11/11 03:25:18 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int ft_atoi(const char *nbr)
{
	int n;
	char g;
	
	g = 0;
	n = 0;
	if (*nbr == '-')
	{
		g = 1;
		nbr++;
	}
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (-1);
		n *= 10;
		n += *nbr - '0';
		nbr++;
	}
	if (g)
		n *= -1;
	return n;
}