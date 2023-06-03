/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:20:45 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 06:28:18 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define MAGENTA "\033[1;35m"
# define CYAN     "\033[1;36m"
# define RESET   "\033[0m"
# define MAXINT 2147483647

typedef struct s_philo	t_philo;
typedef struct s_params
{
	int				nphilos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nmeals;
	int				dead;
	int				allate;
	long			starttime;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	t_philo			*philo;
}	t_params;

struct s_philo
{
	int				id;
	pthread_t		tid;
	int				meals_eaten;
	int				lf;
	int				rf;
	int				stop;
	unsigned long	t_of_last_meal;
	t_params		*params;
};
// init.c
void			init_params(int ac, char **av, t_params *params);
int				init_mutex(t_params *params);
int				init_threads(t_params *params);
int				init_philo(t_params *params);
// msg.c
void			print_msg(t_philo *philo, int id, char *msg);
// utils.c
int				ft_atoi(char *str);
int				ft_isalpha(int c);
// time.c
unsigned long	actual_time(void);
void			ft_usleep_ms(int time_in_ms);

// error.c
int				myperror(char *s);
//simulation.c
void			*philosopher(void *arg);
void			*monitor(void *arg);
//actions.c
int				pick_up_forks(t_philo *philo);
void			put_down_fork(t_philo *philo);
int				eating(t_philo *philo);
void			thinking(t_philo *philo);
void			sleeping(t_philo *philo);
//end.c
void			philostop(t_params *params);
int				end_threads(t_params *params);
void			destroy_mutex(t_params *params);
void			free_stuff(t_params *params);
#endif
