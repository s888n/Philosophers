/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:46:38 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 10:53:59 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_params(t_params *params, int ac, char **av)
{
	params->n_philos = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		params->nmeals = ft_atoi(av[5]);
	else
		params->nmeals = -1;
	params->stop = 0;
	params->full = 0;
	params->pid = malloc(sizeof(int) * params->n_philos);
	if (!params->pid)
		myperror("Malloc Failled");
	init_semaphores(params);
}

void	init_semaphores(t_params *params)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	params->forks = sem_open("/forks", O_CREAT, 0644, params->n_philos);
	params->write = sem_open("/write", O_CREAT, 0644, 1);
	if (params->forks == SEM_FAILED || \
		params->write == SEM_FAILED)
		myperror("Sem_open Failed");
}

void	init_processes(t_params *params)
{
	int	i;

	i = 0;
	params->start_time = actual_time();
	while (i < params->n_philos)
	{
		params->pid[i] = fork();
		if (params->pid[i] == 0)
			init_philos(params, i);
		if (params->pid[i] == -1)
			myperror("Fork Failed");
		i++;
	}
}

void	init_philos(t_params *params, int id)
{
	t_philo	philo;

	philo.id = id + 1;
	philo.meals_eaten = 0;
	philo.dead = 0;
	philo.time_of_last_meal = params->start_time;
	philo.params = params;
	philosopher(&philo);
}
