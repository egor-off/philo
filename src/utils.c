/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:38:05 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/05 23:48:44 by jjoan            ###   ########.fr       */
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

void	print_er(const char *s)
{
	int	len;

	len = ft_strlen(s);
	write(2, "Error: ", 7);
	write(2, s, len);
	write(2, "\n", 1);
	exit(1);
}

long	ft_atol(const char *str)
{
	unsigned long	res;

	res = 0;
	if (*str < 48 || *str > 57)
		print_er("invalid number");
	while (*str >= 48 && *str <= 57)
		res = res * 10 + (*str++ - 48);
	return (res);
}

short	check_time(t_ph *p, t_time *now)
{
	if (((now->tv_sec - p->last_eat->tv_sec) * 1000000)
		+ (now->tv_usec - p->last_eat->tv_usec) < p->boss->time_death)
		return (1);
	return (0);
}
