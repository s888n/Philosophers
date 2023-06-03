/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:10:33 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 06:23:40 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_params(int ac, char **av, t_params *params)
{
	params->nphilos = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
	params->allate = 0;
	params->starttime = actual_time();
	params->nmeals = -1;
	if (ac == 6)
		params->nmeals = ft_atoi(av[5]);
}

int	init_mutex(t_params *params)
{
	int	i;

	i = -1;
	params->forks = malloc(params->nphilos * sizeof(pthread_mutex_t));
	while (++i < params->nphilos)
		if (pthread_mutex_init(&params->forks[i], NULL) != 0)
			return (myperror("pthread_init_mutex failed"));
	if (pthread_mutex_init(&params->writing, NULL) != 0)
		return (myperror("Pthread_init_mutex failed"));
	return (1);
}

int	init_philo(t_params *params)
{
	int	i;

	i = 0;
	params->philo = malloc(params->nphilos * sizeof(t_philo));
	if (!params->philo)
		return (myperror("Malloc Failed"));
	while (i < params->nphilos)
	{
		params->philo[i].id = i + 1;
		params->philo[i].meals_eaten = 0;
		params->philo[i].lf = i;
		params->philo[i].rf = (i + 1) % params->nphilos;
		params->philo[i].stop = 0;
		params->philo[i].params = params;
		i++;
	}
	return (1);
}

int	init_threads(t_params *params)
{
	int			i;
	pthread_t	mtid;

	i = -1;
	while (++i < params->nphilos)
		if (i % 2 == 0)
			if (pthread_create(&(params->philo[i].tid), NULL, philosopher, \
				(void *)&(params->philo[i])) != 0)
				return (myperror("Pthread_create Failed"));
	i = -1;
	usleep(500);
	while (++i < params->nphilos)
		if (i % 2 == 1)
			if (pthread_create(&(params->philo[i].tid), NULL, philosopher, \
				(void *)&(params->philo[i])) != 0)
				return (myperror("Pthread_create Failed"));
	if (pthread_create(&mtid, NULL, monitor, params) != 0)
		return (myperror("Pthread_create Failed"));
	if (pthread_join(mtid, NULL) != 0)
		return (myperror("Pthread_join Failed"));
	return (1);
}
