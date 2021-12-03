/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:34:25 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/02 22:23:31 by jjoan            ###   ########.fr       */
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
	usleep(*p->time_sleep);
	talk_thinking(p);
}

void	*check_death(void *ph)
{
	t_ph	*p;
	t_time	now;

	p = (t_ph *)ph;
	gettimeofday(&now, NULL);
	if (p->last_eat->tv_usec == 0)
		gettimeofday(p->last_eat, NULL);
	while (now.tv_usec - p->last_eat->tv_usec < *(p->time_death))
		gettimeofday(&now, NULL);
	talk_death(p);
	return (NULL);
}

void	*phil(void *s)
{
	t_ph			*p;
	pthread_t		inside;
	unsigned short	flag;

	flag = 1;
	p = (t_ph *) s;
	printf("in philo thread = %zu %p\n", p->num, p);
	while (1)
	{
		if (flag)
		{
			printf("in while thread = %zu %p\n", p->num, p);
			pthread_create(&inside, NULL, check_death, (void *)p);
			printf("in while thread = %zu %p\n", p->num, p);
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
	printf("boss->num = %zu\n", boss->num);
	while (i + 1 <= boss->num)
	{
		printf("boss->num = %zu\n", boss->num);
		boss->ph[i]->num = i + 1;
		printf("boss->num = %zu %zu\n%p\n%p\n", boss->ph[i]->num, i, boss->ph[i], boss->ph);
		pthread_create(&boss->ph[i]->t, NULL, phil, (void *) boss->ph[i]);
		if (i == 0)
			gettimeofday(boss->start, NULL);
		i++;
		usleep(100);
		printf("boss->num = %zu\n", boss->num);
	}
	i = 0;
	while (i < boss->num)
		pthread_join(boss->ph[i++]->t, NULL);
}
