/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:11:05 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/11 17:31:55 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/cdefs.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>

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
	size_t			num;
	sem_t			*talk;
	sem_t			*forks;
	sem_t			*counter;
	sem_t			*sim;
	t_time			*start;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				count_eat;
	long			last_eat;
};

//utils
long	ft_atol(const char *str);
int		print_er(const char *s);
void	sleeping(unsigned int time, t_bos *b);
long	get_time(t_bos *b);
short	get_time_eat(t_bos *b);

//main
int		mall_and_init(t_bos *boss);
void	start_forks(t_bos *boss);
void	destroy(t_bos *b);
void	*count_check(void *boss);
void	start_proc(t_bos *b);

#endif
