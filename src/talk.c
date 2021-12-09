/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/09 18:14:10 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	talk_forks(t_ph *p)
{
	t_time	now;

	pthread_mutex_lock(p->left);
	gettimeofday(&now, NULL);
	if (p->boss->sim)
		printf("%ld #%zu has taken the fork\n", get_time(p), p->num);
}

void	talk_eating(t_ph *p)
{
	unsigned int	eat;

	eat = p->boss->time_eat * 1000;
	pthread_mutex_lock(p->right);
	p->last_eat = get_time(p);
	if (p->boss->sim)
		printf("%ld #%zu is eating\n", p->last_eat, p->num);
	usleep(eat);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	talk_sleeping(t_ph *p)
{
	unsigned int	sleep;

	sleep = p->boss->time_sleep * 1000;
	if (p->boss->sim)
		printf("%ld #%zu is sleeping\n", get_time(p), p->num);
	usleep(sleep);
}

void	talk_thinking(t_ph *p)
{
	if (p->boss->sim)
		printf("%ld #%zu is thinking\n", get_time(p), p->num);
}

void	talk_death(t_ph *p)
{
	if (p->boss->sim)
	{
		p->boss->sim = 0;
		printf("%ld #%zu died\n", get_time(p), p->num);
	}
}
