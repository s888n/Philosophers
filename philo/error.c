/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:09:11 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/24 21:10:14 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	myperror(char *msg)
{
	myputstr("Error : ");
	myputstr(msg);
	myputstr(" !!!\n");
	return (0);
}
