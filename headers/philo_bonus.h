/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:11:05 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/08 23:29:57 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/cdefs.h>

# define FORKS "/forkss"
# define TALK "/talking"
# define COUNT "/counter_eatings"
# define SIM "/simulation_mode"

typedef struct s_boss	t_bos;
typedef struct timeval	t_time;

struct s_boss
{
	unsigned short	id;
	pid_t			*pid;
	sem_t			*talk;
	sem_t			*forks;
	sem_t			*counter;
	sem_t			*sim;
	int				time_death;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	count_eat;
	size_t			num;
	t_time			*start;
};

//utils
long	ft_atol(const char *str);
int		print_er(const char *s);

//main
int		mall_and_init(t_bos *boss);
void	start_threads(t_bos *boss);
void	destroy(t_bos *b);

//talk
void	check_death(t_bos *bs);

#endif
