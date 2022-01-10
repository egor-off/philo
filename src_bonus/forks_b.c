/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:34:25 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/10 19:25:56 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_bonus.h"

void	*checker(void *boss)
{
	t_bos	*b;
	long	need_check;

	b = (t_bos *) boss;
	need_check = b->last_eat + b->time_death;
	while (1)
	{
		if (get_time(b) < need_check)
			continue ;
		else
		{
			sem_wait(b->talk);
			need_check = b->last_eat + b->time_death;
			sem_post(b->talk);
			if (get_time(b) > need_check)
			{
				sem_wait(b->talk);
				sem_post(b->sim);
				printf("%10ld #%d is dead\n", get_time(b), b->id);
				break ;
			}
		}
	}
	return (NULL);
}

void	routine(t_bos *b)
{
	sem_wait(b->forks);
	sem_wait(b->talk);
	printf("%10ld #%d has taken a fork\n", get_time(b), b->id);
	sem_post(b->talk);
	sem_wait(b->forks);
	sem_wait(b->talk);
	b->last_eat = get_time(b);
	printf("%10ld #%d is eating\n", b->last_eat, b->id);
	sem_post(b->talk);
	sleeping(b->time_eat, b);
	sem_post(b->forks);
	sem_post(b->forks);
	sem_wait(b->talk);
	printf("%10ld #%d is sleeping\n", get_time(b), b->id);
	sem_post(b->talk);
	sleeping(b->time_sleep, b);
	sem_wait(b->talk);
	printf("%10ld #%d is thinking\n", get_time(b), b->id);
	sem_post(b->talk);
}

void	start_proc(t_bos *b)
{
	size_t		counter;
	pthread_t	t;

	counter = 0;
	if (b->id % 2 == 0)
		sleeping(b->time_eat, b);
	pthread_create(&t, NULL, checker, (void *) b);
	pthread_detach(t);
	while (1)
	{
		routine(b);
		if (b->count_eat)
		{
			counter++;
			if (counter == b->count_eat)
				sem_post(b->counter);
		}
	}
}

void	*count_check(void *boss)
{
	t_bos	*b;
	size_t	counter;

	counter = 0;
	b = (t_bos *) boss;
	while (counter < b->count_eat)
	{
		sem_wait(b->counter);
		counter++;
		if (counter == b->num)
		{
			sem_wait(b->talk);
			sem_post(b->sim);
		}
	}
	return (NULL);
}

void	start_forks(t_bos *boss)
{
	size_t		i;
	pid_t		pid;
	pthread_t	t;

	i = 0;
	while (i < boss->num)
	{
		if (i == 0)
			gettimeofday(boss->start, NULL);
		boss->id = i + 1;
		pid = fork();
		if (pid == 0)
			start_proc(boss);
		boss->pid[i] = pid;
		i++;
	}
	pthread_create(&t, NULL, count_check, (void *) boss);
	pthread_detach(t);
}
