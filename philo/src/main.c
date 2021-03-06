/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:53:14 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/12 18:09:49 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	write_info(t_bos *boss, int ac, char **av)
{
	boss->num = ft_atol(av[1]);
	boss->time_death = ft_atol(av[2]);
	boss->time_eat = ft_atol(av[3]);
	boss->time_sleep = ft_atol(av[4]);
	if (ac == 6)
	{
		boss->count_eat = ft_atol(av[5]);
		if (boss->count_eat == -1)
			return (0);
	}
	else
		boss->count_eat = -1;
	if (boss->num < 0 || boss->time_death < 0 || boss->time_eat < 0
		|| boss->time_sleep < 0)
		return (0);
	return (1);
}

void	join(t_bos *b)
{
	size_t	i;

	i = 0;
	if (b->num == 1)
		pthread_detach(b->ph[0].t);
	else
	{
		while (i < b->num)
		{
			pthread_join(b->ph[i].t, NULL);
			i++;
		}
	}
}

static int	start_philo(int ac, char **av)
{
	t_bos	boss;

	if (!write_info(&boss, ac, av))
		return (print_er("invalid numver"));
	if (boss.count_eat == 0 || boss.num == 0)
		return (0);
	if (boss.num > 200)
		return (print_er("dont do it, plz"));
	if (mall_and_init(&boss))
		return (1);
	start_threads(&boss);
	check_death(&boss);
	join(&boss);
	destroy(&boss);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_er("must be 4 or 5 arguments to start philo"));
	return (start_philo(ac, av));
}
