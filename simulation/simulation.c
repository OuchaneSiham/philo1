/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:31:39 by souchane          #+#    #+#             */
/*   Updated: 2024/09/02 13:34:56 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	simulation(t_philo *philos, pthread_mutex_t *n_forks)
{
	pthread_t	watcher;
	int			result1;
	int			result2;
	int			result3;

	result1 = create_threads(philos, &watcher);
	if (result1 != 0)
		return (1);
	result2 = join_threads(philos, watcher);
	if (result2 != 0)
		return (1);
	result3 = destroy_threads(philos, n_forks);
	if (result3 != 0)
		return (1);
	return (0);
}
