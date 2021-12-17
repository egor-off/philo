/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:34:25 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/17 15:40:51 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	routin(t_ph *p)
{
	talk_forks(p);
	talk_eating(p);
	talk_sleeping(p);
	talk_thinking(p);
}

void	*check_death(void *b)
{
	t_bos	*bs;
	size_t	i;

	bs = (t_bos *)b;
	i = 0;
	while (bs->sim)
	{
		if (i == bs->num)
			i = 0;
		pthread_mutex_lock(bs->ph[i].eating);
		// printf("check_death #%zu %ld %ld\n", i + 1, get_time_eat(bs->ph + i), get_time(bs->ph + i));
		if (get_time_eat(bs->ph + i) > bs->time_death)
		{
			bs->sim = 0;
			talk_death(bs->ph + i);
		}
		pthread_mutex_unlock(bs->ph[i].eating);
		i++;
	}
	return (NULL);
}

void	*phil(void *s)
{
	t_ph			*p;

	p = (t_ph *) s;
	while (p->boss->sim)
		routin(p);
	return (NULL);
}

void	start_threads(t_bos *boss)
{
	size_t	i;

	i = 0;
	while (i < boss->num)
	{
		boss->ph[i].num = i + 1;
		pthread_create(&boss->ph[i].t, NULL, phil, (void *) &boss->ph[i]);
		if (i == 0)
			gettimeofday(boss->start, NULL);
		i += 2;
		usleep(50);
	}
	usleep(50);
	i = 1;
	while (i < boss->num)
	{
		boss->ph[i].num = i + 1;
		pthread_create(&boss->ph[i].t, NULL, phil, (void *) &boss->ph[i]);
		i += 2;
		usleep(50);
	}
	i = 0;
	// while (i < boss->num)
	// 	pthread_join(boss->ph[i++].t, NULL);
}
