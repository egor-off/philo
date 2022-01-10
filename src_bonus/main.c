/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:53:14 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/08 21:56:12 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_bonus.h"

static int	write_info(t_bos *boss, int ac, char **av)
{
	boss->num = ft_atol(av[1]);
	boss->time_death = ft_atol(av[2]);
	boss->time_eat = ft_atol(av[3]);
	boss->time_sleep = ft_atol(av[4]);
	if (ac == 6)
	{
		boss->count_eat = ft_atol(av[5]);
		if (!boss->count_eat)
			return (1);
	}
	else
		boss->count_eat = 0;
	if (boss->num || boss->time_death || boss->time_eat || boss->time_sleep)
		return (1);
	return (0);
}

static int	start_philo(int ac, char **av)
{
	t_bos	*boss;

	boss = malloc(sizeof(t_bos));
	if (!boss)
		return (print_er("cannot allocate memory for t_bos"));
	if (!write_info(&boss, ac, av))
		return (print_er("invalid numver"));
	if (mall_and_init(&boss))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_er("must be 4 or 5 arguments to start philo"));
	return (start_philo(ac, av));
}
