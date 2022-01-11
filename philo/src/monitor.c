/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:14 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/11 18:38:10 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static short	need_check(t_ph *p)
{
	if (get_time(p->boss) > p->need_check)
		return (0);
	return (1);
}

void	check_death(t_bos *bs)
{
	size_t	i;
	size_t	counter;

	i = -1;
	counter = 0;
	while (bs->sim)
	{
		i++;
		if (i == bs->num)
		{
			i = 0;
			counter = 0;
		}
		if (bs->ph[i].flag)
			counter++;
		if (counter == bs->num)
			bs->sim = 0;
		if (need_check(bs->ph + i))
			continue ;
		if (get_time_eat(bs->ph + i))
			bs->sim = 0;
		if (get_time_eat(bs->ph + i))
			talk_death(bs->ph + i);
	}
}

void	destroy(t_bos *b)
{
	size_t	i;

	i = b->num - 1;
	while (i + 1)
	{
		pthread_mutex_unlock(b->forks + i);
		pthread_mutex_destroy(b->forks + i);
		pthread_mutex_unlock(&b->ph[i].eating);
		pthread_mutex_destroy(&b->ph[i].eating);
		i--;
	}
	free(b->ph);
	free(b->forks);
	free(b->start);
}
