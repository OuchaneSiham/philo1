/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:23:56 by souchane          #+#    #+#             */
/*   Updated: 2024/09/02 13:33:44 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	printing(t_content *philo, int id, char *move)
{
	pthread_mutex_lock(philo->action_mutex);
	pthread_mutex_lock(philo->gone_mutex);
	if (*philo->gone == 0)
		printf("%lli %i %s\n", get_time() - philo->start_time, id, move);
	pthread_mutex_unlock(philo->gone_mutex);
	pthread_mutex_unlock((philo->action_mutex));
}

void	eating_action(t_content *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printing(philo, philo->index, "has taken a fork");
	if (philo->phs_nb == 1)
	{
		ft_delay(philo, philo->die_time);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	printing(philo, philo->index, "has taken a fork");
	philo->eat = 1;
	printing(philo, philo->index, "is eating");
	pthread_mutex_lock(philo->check_meal_mutex);
	philo->last_meal_check = get_time();
	philo->meals_count++;
	pthread_mutex_unlock(philo->check_meal_mutex);
	ft_delay(philo, philo->eat_time);
	philo->eat = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
