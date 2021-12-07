/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/08 02:20:16 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	talk_forks(t_ph *p)
{
	t_time	now;

	pthread_mutex_lock(p->left);
	gettimeofday(&now, NULL);
	pthread_mutex_lock(p->boss->talk);
	printf("%ld #%zu has taken the fork\n", get_time(p), p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_eating(t_ph *p)
{
	pthread_mutex_lock(p->right);
	p->last_eat = get_time(p);
	pthread_mutex_lock(p->boss->talk);
	printf("%ld #%zu is eating\n", p->last_eat, p->num);
	pthread_mutex_unlock(p->boss->talk);
	usleep(p->boss->time_eat * 1000);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	talk_sleeping(t_ph *p)
{
	pthread_mutex_lock(p->boss->talk);
	printf("%ld #%zu is sleeping\n", get_time(p), p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_thinking(t_ph *p)
{
	pthread_mutex_lock(p->boss->talk);
	printf("%ld #%zu is thinking\n", get_time(p), p->num);
	pthread_mutex_unlock(p->boss->talk);
}

void	talk_death(t_ph *p)
{
	pthread_mutex_lock(p->boss->talk);
	pthread_mutex_lock(p->boss->death);
	printf("%ld #%zu died\n", get_time(p), p->num);
	exit(0);
}
