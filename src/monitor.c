/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:14 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/07 17:42:40 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static short	need_check(t_ph *p)
{
	if (get_time(p->boss) > p->need_check)
		return (0);
	return (1);
}

void	check_death(t_bos *bs)
{
	size_t	i;
	size_t	ans;
	size_t	counter;

	i = -1;
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
		ans = get_time_eat(bs->ph + i);
		if (ans)
			bs->sim = 0;
		if (ans)
			talk_death(bs->ph + i);
	}
}

void	destroy(t_bos *b)
{
	size_t	i;

	i = b->num - 1;
	while (i + 1)
	{
		pthread_detach(b->ph[i].t);
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
