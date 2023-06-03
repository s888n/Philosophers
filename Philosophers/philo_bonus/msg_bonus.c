/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:57:28 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 11:33:04 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	myputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	myperror(char *msg)
{
	myputstr("Error : ");
	myputstr(msg);
	myputstr(" !!!\n");
	exit (1);
}

void	msg(t_philo *philo, char *str)
{
	static int	i;
	char		*clrs[6];

	clrs[0] = CYAN;
	clrs[1] = GREY;
	clrs[2] = MAGENTA;
	clrs[3] = BLUE;
	clrs[4] = YELLOW;
	sem_wait(philo->params->write);
	if (!philo->dead)
	{
		printf("%s%ld\t%d\t%s\n%s", clrs[i], actual_time() \
			- philo->params->start_time, philo->id, str, RESET);
		i++;
		if (i == 5)
			i = 0;
	}
	sem_post(philo->params->write);
}
