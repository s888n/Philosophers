/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:06:02 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/30 10:11:54 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	actual_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((unsigned long) \
		(curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000));
}

void	usleep_bussin_fr_fr_no_cap(int time_in_ms)
{
	unsigned long	start_time;

	start_time = actual_time();
	while (actual_time() < start_time + (unsigned long)time_in_ms)
		usleep(time_in_ms);
}

void	usleep_ms(int time_ms, t_philo *philo)
{
	unsigned long	time_left;
	unsigned long	now;

	time_left = philo->time_of_last_meal + philo->params->time_to_die;
	now = actual_time();
	if (now + (unsigned long)time_ms > time_left)
	{
		time_left -= now;
		usleep_bussin_fr_fr_no_cap(time_left);
		if (philo->dead == 1)
			return ;
		now = actual_time() - philo->params->start_time;
		sem_wait(philo->params->write);
		printf("%s%ld\t%d\tis dead\n", RED, now, philo->id);
		exit(EXIT_FAILURE);
	}
	usleep_bussin_fr_fr_no_cap(time_ms);
}
