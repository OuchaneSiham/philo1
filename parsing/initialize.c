/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:56:17 by souchane          #+#    #+#             */
/*   Updated: 2024/08/26 12:37:28 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	initialize(t_philo *philo, t_content *phs, pthread_mutex_t *n_forks, char **av)
{
	if (check_args(av) != 0)
        return 1;
	if(init_mutex(philo, phs, n_forks, ft_atoi(av[1])))
    {
        ft_putstr_fd("ERROR: init mutex failed\n", 2);
        return 1;
    }
    if(initialize_phs(phs, philo, n_forks, av) != 0)
    {
        ft_putstr_fd("ERROR: init philosophers failed\n", 2);
        return 1;
    }
    return 0;
}
