/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:14 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/23 16:34:21 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	check_death(t_bos *bs)
{
	size_t	i;
	short	ans;
	size_t	counter;

	counter = 0;
	i = 0;
	while (bs->sim)
	{
		if (i == bs->num)
		{
			i = 0;
			counter = 0;
		}
		ans = get_time_eat(bs->ph + i);
		if (bs->ph[i].flag)
			counter++;
		if (ans || counter == bs->num)
		{
			bs->sim = 0;
			if (ans)
				talk_death(bs->ph + i);
		}
		i++;
	}
}

void	destroy(t_bos *b)
{
	size_t	i;

	i = b->num - 1;
	while (i)
	{
		pthread_detach(b->ph[i].t);
		pthread_mutex_unlock(b->forks + i);
		pthread_mutex_destroy(b->forks + i);
		i--;
	}
	free(b->ph);
	free(b->forks);
	free(b->start);
}
