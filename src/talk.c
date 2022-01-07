/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/07 18:37:12 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	routine(t_ph *p)
{
	pthread_mutex_lock(p->left);
	if (p->boss->sim)
		printf("%10ld #%zu has taken the fork\n", get_time(p->boss), p->num);
	pthread_mutex_lock(p->right);
	pthread_mutex_lock(&p->eating);
	p->last_eat = get_time(p->boss);
	pthread_mutex_unlock(&p->eating);
	if (p->boss->sim)
		printf("%10ld #%zu is eating\n", p->last_eat, p->num);
	sleeping(p->boss->time_eat, p);
	p->need_check = p->last_eat + p->boss->time_death;
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
	if (p->boss->sim)
		printf("%10ld #%zu is sleeping\n", get_time(p->boss), p->num);
	sleeping(p->boss->time_sleep, p);
	if (p->boss->sim)
		printf("%10ld #%zu is thinking\n", get_time(p->boss), p->num);
}

void	talk_death(t_ph *p)
{
	printf("%10ld #%zu died\n", get_time(p->boss), p->num);
}

void	sleeping(unsigned int time, t_ph *p)
{
	unsigned int	now;
	unsigned int	res;

	now = get_time(p->boss);
	res = now + time;
	while (now < res && p->boss->sim)
	{
		usleep(100);
		now = get_time(p->boss);
	}
}
