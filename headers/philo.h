/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:11:05 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/01 02:02:16 by jjoan            ###   ########.fr       */
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

struct s_philo
{
	pthread_t		num;
	unsigned int	left;
	unsigned int	right;
};

struct s_tab
{
	pthread_mutex_t	*forks;
};

struct s_boss
{
	t_ph			*ph;
	t_tab			*t_tab;
	pthread_mutex_t	death;
	size_t			num;
	size_t			time_death;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			count_eat;
};

void	print_er(const char *s);
void	get_info(t_bos *boss, int ac, char **av);

#endif
