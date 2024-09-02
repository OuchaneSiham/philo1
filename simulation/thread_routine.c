/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:07:04 by souchane          #+#    #+#             */
/*   Updated: 2024/09/02 13:41:06 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_even(int n)
{
	while (n > 0)
	{
		n -= 2;
	}
	return (n == 0);
}

void	*start_routine_function(void *sole_arg)
{
	t_content	*phs;

	phs = (t_content *)sole_arg;
	if (is_even(phs->index))
		ft_delay(phs, 1);
	while (1)
	{
		pthread_mutex_lock(phs->gone_mutex);
		if (*phs->gone == 1)
		{
			pthread_mutex_unlock(phs->gone_mutex);
			break ;
		}
		pthread_mutex_unlock(phs->gone_mutex);
		eating_action(phs);
		printing(phs, phs->index, "is sleeping");
		ft_delay(phs, phs->sleep_time);
		printing(phs, phs->index, "is thinking");
	}
	return (NULL);
}

int	create_threads(t_philo *simu, pthread_t *watcher)
{
	int	i;

	if (pthread_create(watcher, NULL, &tracking, simu->philos) != 0)
	{
		ft_putstr_fd("ERROR: creation of threads failed\n", 2);
		return (1);
	}
	i = 0;
	while (i < simu->philos[0].phs_nb)
	{
		if (pthread_create(&simu->philos[i].id_thread, NULL
				, &start_routine_function, &simu->philos[i]) != 0)
		{
			ft_putstr_fd("ERROR: creation of threads failed\n", 2);
			return (1);
		}
		i++;
		usleep(100);
	}
	return (0);
}
