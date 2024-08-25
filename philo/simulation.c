/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:27:21 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 22:58:23 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(t_philo *philo)
{
	int	x;

	x = 0;
	pthread_mutex_lock(&(philo->params->writing));
	if (philo->stop)
		x = 1;
	pthread_mutex_unlock(&(philo->params->writing));
	return (x);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->params->writing);
	philo->t_of_last_meal = actual_time();
	pthread_mutex_unlock(&philo->params->writing);
	while (1)
	{
		if (check(philo))
			break ;
		if (!eating(philo))
			break ;
		if (check(philo))
			break ;
		sleeping(philo);
		if (check(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}

int	is_full(t_philo *philo, int i)
{
	if (philo[i].params->allate == philo[i].params->nphilos)
	{
		philostop(philo->params);
		printf("%ld\tall philosophers are full\n", \
		actual_time() - philo->params->starttime);
		pthread_mutex_unlock(&philo->params->writing);
		return (1);
	}
	return (0);
}

int	is_dead(t_philo *philo, int i)
{
	if (actual_time() - philo[i].t_of_last_meal \
	> (unsigned long)philo->params->time_to_die)
	{
		philostop(philo->params);
		printf("%ld\t%d is dead\n", \
		actual_time() - philo->params->starttime, philo[i].id);
		pthread_mutex_unlock(&philo->params->writing);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	int			i;
	int			n;
	t_params	*params;
	t_philo		*philo;

	params = (t_params *)arg;
	philo = params->philo;
	n = params->nphilos;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&params->writing);
		if (is_full(philo, i))
			break ;
		if (is_dead(philo, i))
		{
			pthread_mutex_unlock(&params->writing);
			break ;
		}
		pthread_mutex_unlock(&params->writing);
		i = (i + 1) % n;
		usleep(500);
	}
	return (NULL);
}
