/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:53:01 by srachdi           #+#    #+#             */
/*   Updated: 2023/05/26 23:08:41 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <signal.h>
# include <fcntl.h>
# include <stdlib.h>

# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN     "\033[1;36m"
# define GREY     "\033[1;37m"
# define WHITE    "\033[1;39m"
# define RESET   "\033[0m"
# define MAXINT 2147483647

typedef struct s_params
{
	int				n_philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				nmeals;
	unsigned long	start_time;
	int				full;
	int				stop;
	sem_t			*forks;
	sem_t			*write;
	int				*pid;
	struct t_philo	*philo;
}	t_params;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	int					dead;	
	unsigned long		time_of_last_meal;
	t_params			*params;
}	t_philo;

//main_bonus.c
void			check_args(char **av);
void			waiter(t_params *params);
int				main(int ac, char **av);
//init.c
void			init_params(t_params *params, int ac, char **av);
void			init_semaphores(t_params *params);
void			init_processes(t_params *params);
void			init_philos(t_params *params, int id);
//simulation.c
void			philosopher(t_philo *philo);
void			grim_reaper(t_philo *philo);
//actions.c
int				pick_up_forks(t_philo *philo);
void			put_down_fork(t_philo *philo);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
//time.c
unsigned long	actual_time(void);
void			usleep_ms(int time_ms, t_philo *philo);
//utils.c
int				ft_isspace(char c);
int				ft_isdigit(char c);
int				ft_atoi(char *str);
int				ft_isalpha(int c);
//end.c
void			kill_processes(t_params *params);
void			destroy_semaphores(t_params *params);
//msg.c
void			myputstr(char *s);
void			myperror(char *msg);
void			msg(t_philo *philo, char *str);
#endif
