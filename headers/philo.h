/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:11:05 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/09 18:09:08 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo	t_ph;
typedef struct s_table	t_tab;
typedef struct s_boss	t_bos;
typedef struct timeval	t_time;

struct s_philo
{
	size_t			num;
	pthread_t		t;
	pthread_t		c;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	long			last_eat;
	t_bos			*boss;
};

struct s_boss
{
	t_ph			*ph;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
	pthread_mutex_t	*talk;
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
long	get_time_eat(t_ph *p);

//main
int		mall_and_init(t_bos *boss);
void	start_threads(t_bos *boss);

//talk
void	talk_forks(t_ph *p);
void	talk_eating(t_ph *p);
void	talk_sleeping(t_ph *p);
void	talk_thinking(t_ph *p);
void	talk_death(t_ph *p);

#endif
