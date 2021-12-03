/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/03 22:55:59 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	talk_forks(t_ph *p)
{
	long	sec;
	int		msec;

	pthread_mutex_lock(p->left);
	pthread_mutex_lock(p->boss->talk);
	gettimeofday(p->now, NULL);
	sec = p->now->tv_sec;
	msec = p->now->tv_usec / 1000;
	printf("%ld %d #%zu has taken the fork\n", sec, msec, p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_eating(t_ph *p)
{
	long	sec;
	int		msec;

	pthread_mutex_lock(p->right);
	gettimeofday(p->last_eat, NULL);
	sec = p->now->tv_sec;
	msec = p->now->tv_usec / 1000;
	pthread_mutex_lock(p->boss->talk);
	printf("%ld %d #%zu is eating\n", sec, msec, p->num);
	pthread_mutex_unlock(p->boss->talk);
	usleep(p->boss->time_eat);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	talk_sleeping(t_ph *p)
{
	long	sec;
	int		msec;

	gettimeofday(p->now, NULL);
	sec = p->now->tv_sec;
	msec = p->now->tv_usec / 1000;
	pthread_mutex_lock(p->boss->talk);
	printf("%ld %d #%zu is sleeping\n", sec, msec, p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_thinking(t_ph *p)
{
	long	sec;
	int		msec;

	gettimeofday(p->now, NULL);
	sec = p->now->tv_sec;
	msec = p->now->tv_usec / 1000;
	pthread_mutex_lock(p->boss->talk);
	printf("%ld %d #%zu is thinking\n", sec, msec, p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_death(t_ph *p)
{
	pthread_mutex_lock(p->boss->talk);
	pthread_mutex_lock(p->boss->death);
	gettimeofday(p->now, NULL);
	printf("%ld %d #%zu died\n", p->now->tv_sec, p->now->tv_usec / 1000, p->num);
	exit(0);
}
