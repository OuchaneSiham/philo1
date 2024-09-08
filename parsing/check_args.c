/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:22:31 by souchane          #+#    #+#             */
/*   Updated: 2024/09/03 16:55:52 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(char **av)
{
	if (ft_atoi(av[1]) > MAXIMUM || ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
	{
		ft_putstr_fd("ERROR: invalid args\n", 2);
		return (1);
	}
	if (av[5] && (ft_atoi(av[5]) < 0))
	{
		ft_putstr_fd("ERROR: last arg invalid\n", 2);
		return (1);
	}
	return (0);
}
