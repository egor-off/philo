/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:04:14 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/10 20:06:08 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_bonus.h"

void	destroy(t_bos *b)
{
	size_t	i;

	i = 0;
	sem_wait(b->sim);
	while (i < b->num)
	{
		kill(b->pid[i], SIGKILL);
		i++;
	}
	free(b->pid);
	free(b->start);
	free(b);
}
