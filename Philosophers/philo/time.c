/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:35:44 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 11:35:49 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	actual_time(void)
{
	static struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((unsigned long) \
	(curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000));
}

void	ft_usleep_ms(int time_in_ms)
{
	unsigned long	start_time;

	start_time = actual_time();
	while (actual_time() < start_time + (unsigned long)time_in_ms)
		usleep(time_in_ms);
}
