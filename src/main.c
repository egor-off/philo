/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:53:14 by jjoan             #+#    #+#             */
/*   Updated: 2021/12/07 14:12:31 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	start_philo(int ac, char **av)
{
	t_bos	boss;

	write_info(&boss, ac, av);
	mall_and_init(&boss);
	start_threads(&boss);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		print_er("must be 4 or 5 arguments to start philo");
	start_philo(ac, av);
}
