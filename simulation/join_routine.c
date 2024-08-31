/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:16:28 by souchane          #+#    #+#             */
/*   Updated: 2024/08/26 13:13:38 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void destroy_forks(pthread_mutex_t *forks, int num_forks)
{
    int i;

    i = 0;
    while (i < num_forks)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
}

int join_threads(t_philo *simu, pthread_t watcher)
{
    int i;
    if (pthread_join(watcher, NULL) != 0)
    {
        ft_putstr_fd("ERROR: joining of threads failed\n", 2);
        return 1;
    }

  i = 0;
    while (i < simu->philos[0].phs_nb)
    {
        if (pthread_join(simu->philos[i].id_thread, NULL) != 0)
        {
             ft_putstr_fd("ERROR: joining of threads failed\n", 2);
            return 1;
        }
        i++;
    }

    return 0;
}
int destroy_threads(t_philo *philo, pthread_mutex_t *n_forks)
{
    int i;
    i = 0;
    if(pthread_mutex_destroy(&philo->action_mutex) != 0 ||
	    pthread_mutex_destroy(&philo->gone_mutex) != 0 ||
	    pthread_mutex_destroy(&philo->check_meal_mutex) != 0)
        return 1;
    destroy_forks(n_forks, philo->philos[0].phs_nb);
    return 0;
}
