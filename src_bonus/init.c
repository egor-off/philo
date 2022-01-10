/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:43:13 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/08 23:39:05 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_bonus.h"

int	open_sem(t_bos *boss)
{
	sem_unlink(FORKS);
	boss->forks = sem_open(FORKS, O_CREAT, S_IRWXU, boss->num);
	if (boss->forks == SEM_FAILED)
		return (1);
	if (boss->count_eat)
	{
		sem_unlink(COUNT)
		boss->counter = sem_open(COUNT, O_CREAT, S_IRWXU, boss->num);
		if (boss->counter == SEM_FAILED)
			return (1);
	}
	sem_unlink(TALK);
	boss->talk = sem_open(TALK, O_CREAT, S_IRWXU, 1);
	if (boss->talk == SEM_FAILED)
		return (1);
	sem_unlink(SIM);
	boss->sim = sem_open(SIM, O_CREAT, S_IRWXU, 0);
	if (boss->sim == SEM_FAILED)
		return (1);
	return (0);
}

int	mall_and_init(t_bos *boss)
{
	boss->start = malloc(sizeof(t_time));
	if (!boss->start)
		return (print_er("cannot allocate memory"));
	boss->pid = malloc(sizeof(pid_t) * boss->num);
	if (!boss->pid)
		return (print_er("cannot allocate memory"));
	if (open_sem(boss))
		return (print_er("cannot init semaphores"));
	return (0);
}
