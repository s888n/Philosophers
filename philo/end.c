/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:07:14 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 06:19:49 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philostop(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->nphilos)
		params->philo[i].stop = 1;
}

int	end_threads(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->nphilos)
		if (pthread_join(params->philo[i].tid, NULL))
			return (myperror("Pthread_join Failed"));
	return (1);
}

void	destroy_mutex(t_params *params)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&params->writing);
	while (++i < params->nphilos)
	{
		pthread_mutex_unlock(&params->forks[i]);
		pthread_mutex_destroy(&params->forks[i]);
	}
}

void	free_stuff(t_params *params)
{
	if (params->forks)
		free(params->forks);
	if (params->philo)
		free(params->philo);
}
