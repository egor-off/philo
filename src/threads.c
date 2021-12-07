/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:34:25 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/07 14:28:26 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	eat(t_ph *p)
{
	talk_forks(p);
	talk_eating(p);
}

void	sleep_and_think(t_ph *p)
{
	talk_sleeping(p);
	usleep(p->boss->time_sleep);
	talk_thinking(p);
}

void	*check_death(void *ph)
{
	t_ph	p;
	t_time	now;
	int		death;

	p = *(t_ph *) ph;
	death = p.boss->time_death;
	while (!p.last_eat->tv_sec)
		;
	gettimeofday(&now, NULL);
	while (((now.tv_sec - p.last_eat->tv_sec) * 1000000)
		+ (now.tv_usec - p.last_eat->tv_usec) < death)
		gettimeofday(&now, NULL);
	talk_death(&p);
	return (NULL);
}

void	*phil(void *s)
{
	t_ph			*p;
	pthread_t		inside;
	unsigned short	flag;

	flag = 1;
	p = (t_ph *) s;
	printf("hohoho\n");
	while (1)
	{
		if (flag)
		{
			pthread_create(&inside, NULL, check_death, (void *)p);
			flag = 0;
		}
		eat(p);
		sleep_and_think(p);
	}
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
		i++;
		usleep(5);
	}
	i = 0;
	while (i < boss->num)
		pthread_join(boss->ph[i++].t, NULL);
}
