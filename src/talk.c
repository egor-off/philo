/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/23 14:54:50 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	routine(t_ph *p)
{
	pthread_mutex_lock(p->left);
	if (p->boss->sim)
		printf("%ld #%zu has taken the fork\n", get_time(p), p->num);
	pthread_mutex_lock(p->right);
	p->last_eat = get_time(p);
	if (p->boss->sim)
		printf("%ld #%zu is eating\n", p->last_eat, p->num);
	sleeping(p->boss->time_eat, p);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
	if (p->boss->sim)
		printf("%ld #%zu is sleeping\n", get_time(p), p->num);
	sleeping(p->boss->time_sleep, p);
	if (p->boss->sim)
		printf("%ld #%zu is thinking\n", get_time(p), p->num);
}

void	talk_death(t_ph *p)
{
	printf("%ld #%zu died\n", get_time(p), p->num);
}

void	sleeping(unsigned int time, t_ph *p)
{
	unsigned int	now;
	unsigned int	res;

	now = get_time(p);
	res = now + time;
	while (now < res && p->boss->sim)
	{
		usleep(100);
		now = get_time(p);
	}
}
