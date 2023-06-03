/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:43:35 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 10:53:16 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_processes(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->n_philos)
		kill(params->pid[i], SIGINT);
}

void	destroy_semaphores(t_params *params)
{
	sem_close(params->forks);
	sem_unlink("/forks");
	sem_unlink("/write");
}
