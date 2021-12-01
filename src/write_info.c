/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:43:13 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/01 01:01:39 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long	ft_atoi(const char *str)
{
	long	res;
	long	flag;

	res = 0;
	flag = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
		res = res * 10 + (*str++ - 48);
	return (flag * res);
}

void	write_info(t_bos *boss, int ac, char **av)
{
	boss->num = ft_atoi(av[1]);
	boss->time_death = ft_atoi(av[2]);
	boss->time_eat = ft_atoi(av[3]);
	boss->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		boss->count_eat = ft_atoi(av[5]);
	else
		boss->count_eat = 0;
}
