/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:43:13 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/02 22:12:52 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	write_info(t_bos *boss, int ac, char **av)
{
	boss->num = ft_atol(av[1]);
	boss->time_death = ft_atol(av[2]);
	boss->time_eat = ft_atol(av[3]);
	boss->time_sleep = ft_atol(av[4]);
	if (ac == 6)
		boss->count_eat = ft_atol(av[5]);
	else
		boss->count_eat = 0;
}

void	init_struct(t_bos *boss)
{
	size_t	i;

	i = 0;
	while (i + 1 <= boss->num)
	{
		boss->ph[i]->left = &boss->forks[i];
		boss->ph[i]->death = &boss->death;
		boss->ph[i]->time_death = &boss->time_death;
		boss->ph[i]->time_eat = &boss->time_eat;
		boss->ph[i]->time_sleep = &boss->time_sleep;
		boss->ph[i]->count_eat = &boss->count_eat;
		boss->ph[i]->talk = &boss->talk;
		boss->ph[i]->start = &boss->start;
		if (i + 1 == boss->num)
			boss->ph[i]->right = &boss->forks[0];
		else
			boss->ph[i]->right = &boss->forks[i + 1];
		boss->ph[i]->last_eat = malloc(sizeof(t_time));
		if (!boss->ph[i]->last_eat)
			print_er("cannot allocate memory for timelaps");
		boss->ph[i]->now = malloc(sizeof(t_time));
		if (!boss->ph[i]->now)
			print_er("cannot allocate memory for now timelaps");
		i++;
	}
}

void	init_mutex(t_bos *boss)
{
	size_t	i;

	i = 0;
	if (pthread_mutex_init(boss->death, NULL) < 0)
		print_er("cannot init death mutex");
	if (pthread_mutex_init(boss->talk, NULL) < 0)
		print_er("cannot init talk mutex");
	while (i < boss->num)
	{
		if (pthread_mutex_init(boss->forks, NULL) < 0)
			print_er("cannot init mutexes");
		i++;
	}
}

void	mall_struct(t_bos *boss)
{
	boss->ph = malloc(sizeof(t_ph **));
	if (!boss->ph)
		print_er("cannot allocate memory for threads");
	*(boss->ph) = malloc(sizeof(t_ph *) * boss->num);
	if (!*(boss->ph))
		print_er("cannot allocate memory for philosophers");
	boss->start = malloc(sizeof(t_time));
	if (!boss->start)
		print_er("cannot allocate memory for start");
	boss->talk = malloc(sizeof(pthread_mutex_t));
	if (!boss->talk)
		print_er("cannot allocate memory for talk mutex");
	boss->death = malloc(sizeof(pthread_mutex_t));
	if (!boss->death)
		print_er("cannot allocate memory for death mutex");
	boss->forks = malloc(sizeof(pthread_mutex_t) * boss->num);
	if (!boss->forks)
		print_er("cannot allocate memory for death mutex");
}

void	mall_and_init(t_bos *boss)
{
	printf("hi1\n");
	mall_struct(boss);
	printf("hi1\n");
	init_mutex(boss);
	printf("hi1\n");
	init_struct(boss);
	printf("hi4\n");
}
