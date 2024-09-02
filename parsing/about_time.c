/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:08:58 by souchane          #+#    #+#             */
/*   Updated: 2024/09/02 13:45:13 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time(void)
{
	struct timeval		tv;
	long long			time;

	if (gettimeofday(&tv, NULL))
	{
		ft_putstr_fd("erroe: get_time of days error\n", 2);
		return (-1);
	}
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

int	dead(t_content *phs)
{
	pthread_mutex_lock(phs->gone_mutex);
	if (*phs->gone == 1)
		return (pthread_mutex_unlock(phs->gone_mutex), 1);
	pthread_mutex_unlock(phs->gone_mutex);
	return (0);
}

int	ft_delay(t_content *phs, long milliseconds)
{
	long long	now;

	now = get_time();
	while (get_time() < milliseconds + now)
	{
		if (dead(phs))
			break ;
		usleep(400);
	}
	return (0);
}
