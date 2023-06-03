/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:19:55 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/24 21:20:22 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, int id, char *msg)
{
	static int	i;
	char		*clrs[3];

	clrs[0] = CYAN;
	clrs[1] = MAGENTA;
	pthread_mutex_lock(&philo->params->writing);
	if (!philo->stop)
	{
		printf("%s%lu\t", clrs[i], actual_time() - philo->params->starttime);
		printf("%d ", id);
		printf("%s%s\n", msg, RESET);
	}
	i++;
	if (i == 2)
		i = 0;
}
