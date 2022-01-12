/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:34:25 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/12 18:17:44 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*phil(void *s)
{
	t_ph	*p;
	int		counter;

	p = (t_ph *) s;
	counter = 0;
	if (p->num % 2 == 0)
		sleeping(p->boss->time_eat, p);
	while (p->boss->sim)
	{
		routine1(p);
		if (p->boss->count_eat > 0)
		{
			counter++;
			if (counter >= p->boss->count_eat)
				p->flag = 1;
		}
		routine2(p);
		if (!p->boss->sim)
			return (NULL);
	}
	return (NULL);
}

void	start_threads(t_bos *boss)
{
	size_t	i;

	i = 0;
	while (i < boss->num)
	{
		if (i == 0)
			gettimeofday(boss->start, NULL);
		pthread_create(&boss->ph[i].t, NULL, phil, (void *) &boss->ph[i]);
		i++;
	}
}
