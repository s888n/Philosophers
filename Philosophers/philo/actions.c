/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:04:24 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 06:18:28 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[philo->lf]);
	print_msg(philo, philo->id, " has taken a fork ");
	if (philo->params->nphilos == 1)
	{
		pthread_mutex_unlock(&philo->params->writing);
		return (pthread_mutex_unlock(&philo->params->forks[philo->lf]));
	}
	pthread_mutex_unlock(&philo->params->writing);
	pthread_mutex_lock(&philo->params->forks[philo->rf]);
	print_msg(philo, philo->id, " has taken a fork ");
	pthread_mutex_unlock(&philo->params->writing);
	return (1);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->params->forks[philo->lf]);
	pthread_mutex_unlock(&philo->params->forks[philo->rf]);
}

int	eating(t_philo *philo)
{
	if (!pick_up_forks(philo))
	{
		ft_usleep_ms(philo->params->time_to_die);
		return (0);
	}
	print_msg(philo, philo->id, " is eating ");
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->params->nmeals)
		philo->params->allate++;
	philo->t_of_last_meal = actual_time();
	pthread_mutex_unlock(&philo->params->writing);
	ft_usleep_ms(philo->params->time_to_eat);
	put_down_fork(philo);
	return (1);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, philo->id, " is thinking ");
	pthread_mutex_unlock(&philo->params->writing);
}

void	sleeping(t_philo *philo)
{
	print_msg(philo, philo->id, " is sleeping ");
	pthread_mutex_unlock(&philo->params->writing);
	ft_usleep_ms(philo->params->time_to_sleep);
}
