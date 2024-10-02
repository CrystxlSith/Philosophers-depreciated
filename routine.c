/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:24 by crystal           #+#    #+#             */
/*   Updated: 2024/10/02 12:01:06 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	think_rest(t_philo *data)
{
	// if (dead_philo(data))
	// 	return ;
	ft_print("Is Thinking", data, data->id);
	// if (dead_philo(data))
	// 	return ;
	ft_print("Is sleeping", data, data->id);
	ft_usleep(data->data->t_sleep);
}

int	dead_philo(t_philo *info)
{
	pthread_mutex_lock(&info->data->dead_lock);
	if (info->data->dead == 1)
	{
		pthread_mutex_unlock(&info->data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->data->dead_lock);
	return (0);
}

// void	eat(t_philo *info)
// {
// 	if (dead_philo(info))
// 		return ;
// 	pthread_mutex_lock(info->r_fork);
// 	ft_print("Take a fork", info, info->id);
// 	pthread_mutex_lock(&info->l_fork);
// 	ft_print("Take a fork", info, info->id);
// 	info->eat = 1;
// 	ft_print("As eat", info, info->id);
// 	pthread_mutex_lock(&info->data->eat_lock);
// 	info->last_meal = get_current_time();
// 	info->nb_times_eat += 1;
// 	pthread_mutex_unlock(&info->data->eat_lock);
// 	ft_usleep(info->data->t_eat);
// 	info->eat = 0;
// 	pthread_mutex_unlock(&info->l_fork);
// 	pthread_mutex_unlock(info->r_fork);
// }

void eat(t_philo *info) {
    // Check if the philosopher is dead
    if (dead_philo(info))
        return;

    // Determine the order of locking based on philosopher ID
    if (info->id % 2 == 0) {
        // Even ID: lock right fork first, then left fork
        pthread_mutex_lock(info->r_fork);
        ft_print("Take a fork", info, info->id);
        pthread_mutex_lock(&info->l_fork);
        ft_print("Take a fork", info, info->id);
    } else {
        // Odd ID: lock left fork first, then right fork
        pthread_mutex_lock(&info->l_fork);
        ft_print("Take a fork", info, info->id);
        pthread_mutex_lock(info->r_fork);
        ft_print("Take a fork", info, info->id);
    }

    // Mark as eating
    info->eat = 1;
    ft_print("As eat", info, info->id);

    // Update last meal time and number of times eaten
    pthread_mutex_lock(&info->data->eat_lock);
    info->last_meal = get_current_time();
    info->nb_times_eat += 1;
    pthread_mutex_unlock(&info->data->eat_lock);

    // Simulate eating
    ft_usleep(info->data->t_eat);

    // Mark as not eating
    info->eat = 0;

    // Unlock the forks in the same order
    if (info->id % 2 == 0) {
        pthread_mutex_unlock(&info->l_fork);
        pthread_mutex_unlock(info->r_fork);
    } else {
        pthread_mutex_unlock(info->r_fork);
        pthread_mutex_unlock(&info->l_fork);
    }
}
void	*routine(void *data)
{
	t_philo *info;
	
	info = (t_philo *)data;
	if (info->id % 2 == 0)
		ft_usleep(1);
	while (!dead_philo(info))
	{
		eat(info);
		think_rest(info);
	}
	return (data);
}