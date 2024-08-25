/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:59:17 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/30 10:11:35 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philosopher(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(500);
	while (!philo->dead)
	{
		if (!philo->dead)
			eating(philo);
		if (!philo->dead)
			sleeping(philo);
		if (!philo->dead)
			thinking(philo);
	}
}

void	grim_reaper(t_philo *philo)
{
	unsigned long	now;

	now = actual_time();
	if (now - philo->time_of_last_meal \
	> (unsigned long)philo->params->time_to_die)
	{
		philo->dead = 1;
		sem_wait(philo->params->write);
		printf("%s%lu\t%d is dead.\n", RED, \
			actual_time() - philo->params->start_time, philo->id);
		exit(EXIT_FAILURE);
	}
}
