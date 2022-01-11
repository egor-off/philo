/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:38:05 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/11 15:00:38 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

int	print_er(const char *s)
{
	int	len;

	len = ft_strlen(s);
	write(2, "Error: ", 7);
	write(2, s, len);
	write(2, "\n", 1);
	return (1);
}

long	get_time(t_bos *b)
{
	t_time	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - b->start->tv_sec) * 1000
		+ (now.tv_usec - b->start->tv_usec) / 1000);
}

short	get_time_eat(t_bos *b)
{
	return (get_time(b) - b->last_eat > b->time_death);
}

void	sleeping(unsigned int time, t_bos *b)
{
	unsigned int	now;
	unsigned int	res;

	now = get_time(b);
	res = now + time;
	while (now < res)
	{
		usleep(100);
		now = get_time(b);
	}
}
