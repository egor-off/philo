/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:11:05 by jjoan             #+#    #+#             */
/*   Updated: 2022/01/07 14:11:54 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>

typedef struct s_philo	t_ph;
typedef struct s_boss	t_bos;
typedef struct timeval	t_time;

struct s_philo
{
	size_t			pid;
	pthread_t		t;
	sem_t			*left;
	sem_t			*right;
	long			last_eat;
	t_bos			*boss;
	short			flag;
};

struct s_boss
{
	t_ph			*ph;
	sem_t			*forks;
	size_t			num;
	int				time_death;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	count_eat;
	t_time			*start;
	short			sim;
};

//utils
long	ft_atol(const char *str);
int		print_er(const char *s);
short	check_time(t_ph *p, t_time *now);
long	get_time(t_ph *p);
short	get_time_eat(t_ph *p);
void	sleeping(unsigned int time, t_ph *p);

//main
int		mall_and_init(t_bos *boss);
void	start_threads(t_bos *boss);
void	destroy(t_bos *b);

//talk
void	routine(t_ph *p);
void	talk_death(t_ph *p);

void	check_death(t_bos *bs);

#endif
