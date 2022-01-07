/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:34:25 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/30 19:34:23 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*phil(void *s)
{
	t_ph	*p;
	size_t	counter;

	p = (t_ph *) s;
	counter = 0;
	while (p->boss->sim)
	{
		routine(p);
		if (p->boss->count_eat)
		{
			counter++;
			if (counter == p->boss->count_eat)
				p->flag = 1;
		}
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
		usleep(10);
		i++;
	}
}
