/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/05 22:20:51 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	talk_forks(t_ph *p)
{
	t_time	now;

	pthread_mutex_lock(p->left);
	gettimeofday(&now, NULL);
	pthread_mutex_lock(p->boss->talk);
	printf("%ld %d #%zu has taken the fork\n", now.tv_sec,
		now.tv_usec / 1000, p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_eating(t_ph *p)
{
	pthread_mutex_lock(p->right);
	gettimeofday(p->last_eat, NULL);
	pthread_mutex_lock(p->boss->talk);
	printf("%ld %d #%zu is eating\n", p->last_eat->tv_sec,
		p->last_eat->tv_usec / 1000, p->num);
	pthread_mutex_unlock(p->boss->talk);
	usleep(p->boss->time_eat);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	talk_sleeping(t_ph *p)
{
	t_time	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(p->boss->talk);
	printf("%ld %d #%zu is sleeping\n", now.tv_sec, now.tv_usec / 1000, p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_thinking(t_ph *p)
{
	t_time	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(p->boss->talk);
	printf("%ld %d #%zu is thinking\n", now.tv_sec, now.tv_usec / 1000, p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_death(t_ph *p)
{
	t_time	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(p->boss->talk);
	pthread_mutex_lock(p->boss->death);
	printf("%ld %d #%zu died\n", now.tv_sec, now.tv_usec / 1000, p->num);
	exit(0);
}
