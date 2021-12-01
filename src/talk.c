/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/01 20:27:29 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	talk_forks(t_ph *p)
{
	pthread_mutex_lock(p->left);
	pthread_mutex_lock(*(p->talk));
	gettimeofday(p->now, NULL);
	printf("%d #%zu has taken the fork\n", p->now->tv_usec
		- (*p->start)->tv_usec, p->num);
	pthread_mutex_unlock(*(p->talk));
}

void	talk_eating(t_ph *p)
{
	pthread_mutex_lock(p->right);
	gettimeofday(p->now, NULL);
	pthread_mutex_lock(*(p->talk));
	printf("%d #%zu is eating\n", p->now->tv_usec - (*p->start)->tv_usec,
		p->num);
	pthread_mutex_unlock(*(p->talk));
	gettimeofday(p->last_eat, NULL);
	usleep(*p->time_eat);
	gettimeofday(p->last_eat, NULL);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	talk_sleeping(t_ph *p)
{
	pthread_mutex_lock(*(p->talk));
	gettimeofday(p->now, NULL);
	printf("%d #%zu is sleeping\n", p->now->tv_usec - (*p->start)->tv_usec,
		p->num);
	usleep(*p->time_sleep);
	pthread_mutex_unlock(*(p->talk));
}

void	talk_thinking(t_ph *p)
{
	pthread_mutex_lock(*(p->talk));
	gettimeofday(p->now, NULL);
	printf("%d #%zu is thinking\n", p->now->tv_usec - (*p->start)->tv_usec,
		p->num);
	pthread_mutex_unlock(*(p->talk));
}

void	talk_death(t_ph *p)
{
	pthread_mutex_lock(*(p->talk));
	pthread_mutex_lock(*(p->death));
	gettimeofday(p->now, NULL);
	printf("%d #%zu died\n", p->now->tv_usec - (*p->start)->tv_usec,
		p->num);
	exit(0);
}
