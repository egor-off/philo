/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:38:05 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/07 16:02:45 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

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

long	ft_atol(const char *str)
{
	long	res;

	res = 0;
	if (*str < 48 || *str > 57)
		return (-1);
	while (*str >= 48 && *str <= 57)
		res = res * 10 + (*str++ - 48);
	if (*str == 0)
		return (res);
	return (-1);
}

long	get_time(t_bos *b)
{
	t_time	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - b->start->tv_sec) * 1000
		+ (now.tv_usec - b->start->tv_usec) / 1000);
}

short	get_time_eat(t_ph *p)
{
	long	last_eat;

	pthread_mutex_lock(&p->eating);
	last_eat = p->last_eat;
	pthread_mutex_unlock(&p->eating);
	return (get_time(p->boss) - last_eat > p->boss->time_death);
}
