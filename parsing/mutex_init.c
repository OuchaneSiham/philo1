/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:43:26 by souchane          #+#    #+#             */
/*   Updated: 2024/09/02 13:23:35 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	initialize_single_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
		return (1);
	return (0);
}

int	init_mutex(t_philo *philo, t_content *phs,
	pthread_mutex_t *n_forks, int num_ph)
{
	int	i;

	philo->gone_flag = 0;
	philo->philos = phs;
	if (initialize_single_mutex(&philo->action_mutex) != 0
		|| initialize_single_mutex(&philo->gone_mutex) != 0
		|| initialize_single_mutex(&philo->check_meal_mutex) != 0)
		return (1);
	i = 0;
	while (i < num_ph)
	{
		if (initialize_single_mutex(&n_forks[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
