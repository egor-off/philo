/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:43:13 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/16 13:18:57 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	give_forks(t_bos *boss, pthread_mutex_t **forks, size_t i)
{
	if (i % 2 == 0)
	{
		boss->ph[i].left = *forks + i;
		if (i + 1 == boss->num)
			boss->ph[i].right = *forks;
		else
			boss->ph[i].right = *forks + i + 1;
	}
	else
	{
		boss->ph[i].right = *forks + i;
		if (i + 1 == boss->num)
			boss->ph[i].left = *forks;
		else
			boss->ph[i].left = *forks + i + 1;
	}
	// boss->ph[i].left = *forks + i;
	// if (i + 1 == boss->num)
	// 	boss->ph[i].right = *forks;
	// else
	// 	boss->ph[i].right = *forks + i + 1;
}

void	init_struct(t_bos *boss)
{
	size_t	i;

	i = 0;
	while (i < boss->num)
	{
		boss->ph[i].boss = boss;
		give_forks(boss, &boss->forks, i);
		boss->ph[i].last_eat = 0;
		boss->ph[i].eating = boss->eat + i;
		i++;
	}
}

int	init_mutex(t_bos *boss)
{
	size_t	i;

	i = 0;
	// if (pthread_mutex_init(boss->death, NULL) > 0)
	// 	return (1);
	// if (pthread_mutex_init(boss->talk, NULL) > 0)
	// 	return (1);
	boss->sim = 1;
	while (i < boss->num)
	{
		if (pthread_mutex_init(boss->forks + i, NULL) > 0)
			return (1);
		if (pthread_mutex_init(boss->eat + i, NULL) > 0)
			return (1);
		i++;
	}
	return (0);
}

int	mall_struct(t_bos *boss)
{
	boss->ph = malloc(sizeof(t_ph) * boss->num);
	if (!boss->ph)
		return (1);
	boss->start = malloc(sizeof(t_time));
	if (!boss->start)
		return (1);
	// boss->talk = malloc(sizeof(pthread_mutex_t));
	// if (!boss->talk)
	// 	return (1);
	// boss->death = malloc(sizeof(pthread_mutex_t));
	// if (!boss->death)
	// 	return (1);
	boss->eat = malloc(sizeof(pthread_mutex_t) * boss->num);
	if (!boss->eat)
		return (1);
	boss->forks = malloc(sizeof(pthread_mutex_t) * boss->num);
	if (!boss->forks)
		return (1);
	return (0);
}

int	mall_and_init(t_bos *boss)
{
	if (mall_struct(boss))
		return (print_er("cannot allocate memory"));
	if (init_mutex(boss))
		return (print_er("cannot init mutexes"));
	init_struct(boss);
	return (0);
}
