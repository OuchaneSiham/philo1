/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:23:56 by souchane          #+#    #+#             */
/*   Updated: 2024/08/31 10:03:03 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	printing(t_content *philo, int id, char *move)
{
	size_t t;
	pthread_mutex_lock(philo->action_mutex);
	t = get_time() - philo->start_time;
    pthread_mutex_lock(philo->gone_mutex);
	if (*philo->gone == 0)
		printf("%lli %i %s\n", get_time() - philo->start_time, id , move);
	pthread_mutex_unlock(philo->gone_mutex);	
	pthread_mutex_unlock((philo->action_mutex));
}
void lock_forks(t_content *phs)
{
	pthread_mutex_lock(phs->right_fork);
	printing(phs, phs->index, "has taken a fork");
	if(phs->phs_nb != 1)
	{
		pthread_mutex_lock(phs->left_fork);
		printing(phs, phs->index, "has taken a fork");
	}
}
void unlock_forks(t_content *phs)
{
	if(phs->phs_nb != 1)
		pthread_mutex_unlock(phs->left_fork);
	pthread_mutex_unlock(phs->right_fork);
}
void eating_action(t_content *phs)
{
	lock_forks(phs);
	if(phs->phs_nb == 1)
	{
		ft_delay(phs,phs->die_time);
		unlock_forks(phs);
	}
	pthread_mutex_lock(phs->check_meal_mutex);
	phs->eat = 1;
	phs->last_meal_check = get_time();
	phs->meals_count++;
	pthread_mutex_unlock(phs->check_meal_mutex);
	printing(phs, phs->index, "is eating");
	ft_delay(phs,phs->eat_time);
	phs->eat = 0;
	unlock_forks(phs);
}