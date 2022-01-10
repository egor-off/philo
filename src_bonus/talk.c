/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:22:53 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/08 21:56:50 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_bonus.h"

// remake for sem and proc

void	talk_death(t_ph *p)
{
	printf("%ld #%zu died\n", get_time(p), p->num);
}

void	sleeping(unsigned int time, t_ph *p)
{
	unsigned int	now;
	unsigned int	res;

	now = get_time(p);
	res = now + time;
	while (now < res && p->boss->sim)
	{
		usleep(100);
		now = get_time(p);
	}
}
