/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:49:47 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 23:08:12 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	has_alpha(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (has_alpha(av[i]))
			myperror("Invalid Args");
		if (ft_atoi(av[i]) <= 0 || ft_atoi(av[i]) > MAXINT)
			myperror("Invalid Args");
		i++;
	}
}

void	waiter(t_params *params)
{
	int	status;

	while (params->full < params->n_philos)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		{
			params->stop = 1;
			kill_processes(params);
			sem_close(params->write);
			break ;
		}
		else if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
			params->full++;
	}
	if (params->full == params->n_philos && !params->stop)
	{
		sem_wait(params->write);
		printf("%s***** All philosophers are full ****\n", GREEN);
	}
}

int	main(int ac, char **av)
{
	t_params	params;

	if (ac != 5 && ac != 6)
		myperror(" 5 or 6 args Required");
	check_args(av);
	init_params(&params, ac, av);
	init_processes(&params);
	waiter(&params);
	destroy_semaphores(&params);
	free(params.pid);
	return (0);
}
