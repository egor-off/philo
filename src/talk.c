/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/10 21:27:14 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	talk_forks(t_ph *p)
{
	pthread_mutex_lock(p->left);
	printf("8888 %d\n", p->boss->sim);
	if (p->boss->sim)
		printf("%ld #%zu has taken the fork\n", get_time(p), p->num);
}

void	talk_eating(t_ph *p)
{
	unsigned int	eat;

	eat = p->boss->time_eat * 1000;
	pthread_mutex_lock(p->right);
	printf("mutex %d\n", pthread_mutex_lock(&p->eating));
	p->last_eat = get_time(p);
	if (p->boss->sim)
		printf("%ld #%zu is eating\n", p->last_eat, p->num);
	usleep(eat);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(&p->eating);
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
	printf("%ld #%zu died\n", get_time(p), p->num);
}
