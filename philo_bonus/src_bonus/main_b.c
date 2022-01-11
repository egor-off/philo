/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:53:14 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/11 19:15:59 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	start_forks(t_bos *boss)
{
	size_t		i;
	pid_t		pid;
	pthread_t	t;

	i = 0;
	while (i < boss->num)
	{
		if (i == 0)
			gettimeofday(boss->start, NULL);
		boss->id = i + 1;
		pid = fork();
		if (pid == 0)
			start_proc(boss);
		boss->pid[i] = pid;
		i++;
	}
	if (boss->count_eat)
	{
		pthread_create(&t, NULL, count_check, (void *) boss);
		pthread_detach(t);
	}
}

long	ft_atol(const char *str)
{
	long	res;

	res = 0;
	if (*str < 48 || *str > 57)
		return (-1);
	while (*str >= 48 && *str <= 57)
		res = res * 10 + (*str++ - 48);
	if (*str == 0)
		return (res);
	return (-1);
}

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
	boss->last_eat = 0;
	if (boss->num < 0 || boss->time_death < 0 || boss->time_eat < 0
		|| boss->time_sleep < 0)
		return (0);
	return (1);
}

static int	start_philo(int ac, char **av)
{
	t_bos	*boss;

	boss = malloc(sizeof(t_bos));
	if (!boss)
		return (print_er("cannot allocate memory for t_bos"));
	if (!write_info(boss, ac, av))
		return (print_er("invalid numver"));
	if (boss->count_eat == 0 || boss->num == 0)
	{
		free(boss);
		return (0);
	}
	if (boss->num > 200)
	{
		free(boss);
		return (print_er("don't do it, plz"));
	}
	if (mall_and_init(boss))
		return (1);
	start_forks(boss);
	destroy(boss);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_er("must be 4 or 5 arguments to start philo"));
	return (start_philo(ac, av));
}
