/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:08:11 by pat               #+#    #+#             */
/*   Updated: 2022/11/21 05:57:16 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

static int	print_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

int	check_arg(int ac, char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (print_error("wrong arguments !"));
			j++;
		}
	}
	j = 0;
	while (arg[1][j])
		j++;
	if (j == 1 && arg[1][0] == '0')
		return (print_error("wrong arguments !"));
	return (1);
}

int	ft_atoi(const char *nbr)
{
	long int	n;
	char		g;

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
	if (n > 2147483647 || n < -2147483648)
		return (-1);
	return ((int)n);
}
