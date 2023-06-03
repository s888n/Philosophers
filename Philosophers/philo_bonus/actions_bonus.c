/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:40:23 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/30 10:10:40 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	pick_up_forks(t_philo *philo)
{
	sem_wait(philo->params->forks);
	msg(philo, "has picked up a fork");
	if (philo->params->n_philos == 1)
	{
		usleep_ms(philo->params->time_to_die + 1, philo);
		sem_post(philo->params->forks);
		return (0);
	}
	else
	{
		grim_reaper(philo);
		sem_wait(philo->params->forks);
		msg(philo, "has picked up a fork");
	}
	return (1);
}

void	put_down_fork(t_philo *philo)
{
	sem_post(philo->params->forks);
	sem_post(philo->params->forks);
}

void	eating(t_philo *philo)
{	
	grim_reaper(philo);
	if (pick_up_forks(philo))
	{
		philo->meals_eaten++;
		msg(philo, "is eating");
		usleep_ms(philo->params->time_to_eat, philo);
		put_down_fork(philo);
		grim_reaper(philo);
		philo->time_of_last_meal = actual_time();
		if (philo->meals_eaten == philo->params->nmeals)
			exit(EXIT_SUCCESS);
	}
}

void	sleeping(t_philo *philo)
{
	msg(philo, "is sleeping");
	usleep_ms(philo->params->time_to_sleep, philo);
	grim_reaper(philo);
}

void	thinking(t_philo *philo)
{
	msg(philo, "is thinking");
	grim_reaper(philo);
}
