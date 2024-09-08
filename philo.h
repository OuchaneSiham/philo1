/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:37:10 by souchane          #+#    #+#             */
/*   Updated: 2024/09/03 19:20:49 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define MAXIMUM 300

typedef struct s_content
{
	pthread_t		id_thread;
	int				index;
	int				eat;
	int				meals_count;
	size_t			last_meal_check;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			start_time;
	int				phs_nb;
	int				meals_num_to_eat;
	int				*gone;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*action_mutex;
	pthread_mutex_t	*gone_mutex;
	pthread_mutex_t	*check_meal_mutex;
}					t_content;
typedef struct s_philo
{
	int				gone_flag;
	pthread_mutex_t	gone_mutex;
	pthread_mutex_t	check_meal_mutex;
	pthread_mutex_t	action_mutex;
	t_content		*philos;
}					t_philo;
// about time
long long	get_time(void);
// int		ft_delay(long long milliseconds);
int			ft_delay(t_content *phs, long milliseconds);
// utils
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
// moves
void		printing(t_content *philo, int id, char *move);
void		eating_action(t_content *phs);
// init
int			check_args(char **av);
int			init_mutex(t_philo *philo, t_content *phs,
				pthread_mutex_t *n_forks, int num_ph);
int			initialize(t_philo *philo, t_content *phs,
				pthread_mutex_t *n_forks, char **av);
int			initialize_phs(t_content *phs, t_philo *philo,
				pthread_mutex_t *n_forks, char **av);
// simulation
void		*tracking(void *sole_arg);
int			create_threads(t_philo *simu, pthread_t *watcher);
int			join_threads(t_philo *simu, pthread_t watcher);
int			destroy_threads(t_philo *philo, pthread_mutex_t *n_forks);
int			simulation(t_philo *philos, pthread_mutex_t *n_forks);

#endif
