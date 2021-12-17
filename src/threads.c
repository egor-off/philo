/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:34:25 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/16 13:19:12 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	routin(t_ph *p)
{
	printf("hi8841\n");
	talk_forks(p);
	printf("hi8842\n");
	talk_eating(p);
	printf("hi8843\n");
	talk_sleeping(p);
	printf("hi8844\n");
	talk_thinking(p);
	printf("hi8845\n");
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
		if (pthread_mutex_lock(bs->ph[i].eating))
		{
			i++;
			continue ;
		}
		if (get_time_eat(bs->ph + i) - bs->ph[i].last_eat > bs->time_death)
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
	// unsigned short	flag;

	// flag = 1;
	p = (t_ph *) s;
	printf("hi884 %d\n", p->boss->sim);
	while (p->boss->sim)
	{
		// if (flag)
		// {
		// 	pthread_create(&p->c, NULL, check_death, (void *) p);
		// 	flag = 0;
		// }
		routin(p);
	}
	return (NULL);
}

void	start_threads(t_bos *boss)
{
	size_t	i;

	i = 0;
	printf("hi88\n");
	while (i < boss->num)
	{
		boss->ph[i].num = i + 1;
		pthread_create(&boss->ph[i].t, NULL, phil, (void *) &boss->ph[i]);
		if (i == 0)
			gettimeofday(boss->start, NULL);
		i++;
		usleep(50);
	}
	printf("hi89 %zu\n", i);
	usleep(50);
	i = 1;
	// while (i < boss->num)
	// {
	// 	boss->ph[i].num = i + 1;
	// 	pthread_create(&boss->ph[i].t, NULL, phil, (void *) &boss->ph[i]);
	// 	i += 2;
	// 	usleep(50);
	// }
	printf("hi90 %zu\n", i);
	pthread_create(&boss->c, NULL, check_death, (void *) boss);
	printf("hi91 %zu\n", i);
	i = 0;
	// while (i < boss->num)
	// 	pthread_join(boss->ph[i++].t, NULL);
	pthread_join(boss->c, NULL);
}
