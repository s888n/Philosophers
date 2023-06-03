/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:18:25 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 22:18:42 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (has_alpha(av[i]))
			return (0);
		if (ft_atoi(av[i]) <= 0 || ft_atoi(av[i]) > MAXINT)
		{
			myperror("Invalid Args");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_params	params;

	if (ac != 5 && ac != 6)
		return (myperror("5 or 6 args required"), 1);
	if (!check_args(av))
		return (1);
	init_params(ac, av, &params);
	if (!init_mutex(&params))
		return (1);
	if (!init_philo(&params))
		return (1);
	if (!init_threads(&params))
		return (1);
	if (!end_threads(&params))
		return (1);
	destroy_mutex(&params);
	free_stuff(&params);
	return (0);
}
