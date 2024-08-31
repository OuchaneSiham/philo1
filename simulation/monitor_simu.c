/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_simu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:33:45 by souchane          #+#    #+#             */
/*   Updated: 2024/08/26 14:24:18 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_death(t_content *phs)
{
    int i ;
    i = 0;
    while(i < phs[0].phs_nb)
    {
        pthread_mutex_lock(phs[i].check_meal_mutex);
        if((get_time() - phs[i].last_meal_check >= phs[i].die_time) && phs[i].eat == 0)
        {
            pthread_mutex_unlock(phs[i].check_meal_mutex);
            printing(&phs[i], phs[i].index, "died");
            pthread_mutex_lock(phs[0].gone_mutex);
            *phs->gone = 1;
            pthread_mutex_unlock(phs[0].gone_mutex);
            return 1;
        }
        pthread_mutex_unlock(phs[i].check_meal_mutex);
        i++;
    }
    return 0;
}
int check_all_done_eating(t_content *phs)
{
    int i;
    int done_eating;
    
    if(phs[0].meals_num_to_eat == -1)
        return (0);
    done_eating = 0;
    i = -1;
    while(++i < phs[0].phs_nb)
    {
        pthread_mutex_lock(phs[i].check_meal_mutex);
        if(phs[i].meals_count >= phs[i].meals_num_to_eat)
            done_eating++;
        pthread_mutex_unlock(phs[i].check_meal_mutex);
    }
    if(done_eating == phs[0].phs_nb)
    {
        pthread_mutex_lock(phs[0].gone_mutex);
        *phs->gone = 1;
        pthread_mutex_unlock(phs[0].gone_mutex);
        return 1;
    }
    return 0;
}
void  *tracking(void *sole_arg)
{
    t_content *phs;
    phs = (t_content *)sole_arg;
    while(1)
    {
        if(check_death(phs) != 0 || check_all_done_eating(phs) != 0)
        break;
    }
    return NULL;
}
