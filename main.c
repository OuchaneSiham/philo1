/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:38:41 by souchane          #+#    #+#             */
/*   Updated: 2024/09/03 19:21:42 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int				result;
	t_philo			philo;
	t_content		phs[MAXIMUM];
	pthread_mutex_t	n_forks[MAXIMUM];

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		return (1);
	}
	result = initialize(&philo, phs, n_forks, av);
	if (result != 0)
		return (1);
	if (simulation(&philo, n_forks))
		return (1);
	return (0);
}
