/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:40:10 by souchane          #+#    #+#             */
/*   Updated: 2024/08/25 15:28:47 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"
void	parse_args(t_content *philo, char **av)
{
	philo->phs_nb = ft_atoi(av[1]);
	philo->die_time= ft_atoi(av[2]);
	philo->eat_time = ft_atoi(av[3]);
	philo->sleep_time = ft_atoi(av[4]);
	if (av[5])
		philo->meals_num_to_eat = ft_atoi(av[5]);
	else
		philo->meals_num_to_eat = -1;
}

// Initializing the philosophers

int 	initialize_phs(t_content *phs, t_philo *philo, pthread_mutex_t *n_forks,
		char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		phs[i].index = i + 1;
		phs[i].eat = 0;
		phs[i].meals_count = 0;
		parse_args(&phs[i], av);
		phs[i].start_time = get_time();
		phs[i].last_meal_check = get_time();
		phs[i].action_mutex = &philo->action_mutex;
		phs[i].gone_mutex = &philo->gone_mutex;
		phs[i].check_meal_mutex = &philo->check_meal_mutex;
		phs[i].gone = &philo->gone_flag;
		phs[i].left_fork = &n_forks[i];
		if (i == 0)
			phs[i].right_fork = &n_forks[phs[i].phs_nb - 1];
		else
			phs[i].right_fork = &n_forks[i - 1];
		i++;
	}
	return 0;
}
