/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:24 by crystal           #+#    #+#             */
/*   Updated: 2024/08/19 14:39:21 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	think(t_philo *data)
{
	ft_print("Is Thinking 🤔\n", data, data->id);
}

void	rest(t_philo *data)
{
	ft_print("Is sleeping 😴🛌\n", data, data->id);
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

void	eat(t_philo *info)
{
	pthread_mutex_lock(info->r_fork);
	ft_print("Take a fork 🍴\n", info, info->id);
	pthread_mutex_lock(&info->l_fork);
	ft_print("Take a fork 🍴\n", info, info->id);
	info->eat = 1;
	ft_print("As eaten 🍠\n", info, info->id);
	info->last_meal = get_current_time();
	info->nb_times_eat += 1;
	ft_usleep(info->data->t_eat);
	info->eat = 0;
	pthread_mutex_unlock(&info->l_fork);
	pthread_mutex_unlock(info->r_fork);
}

void	*routine(void *data)
{
	// int	i;
	t_philo *info;
	
	info = (t_philo *)data;
	// i = 0;
	if (info->id % 2 == 0)
		ft_usleep(1);
	while (!dead_philo(info))
	{
		eat(info);
		think(info);
		rest(info);
		// i++;	
	}
	// while (1)
	// {
	// 	if (dead_philo(info))
	// 		break;
	// 	eat(info);
	// 	if (dead_philo(info))
	// 		break;
	// 	think(info);
	// 	if (dead_philo(info))
	// 		break;
	// 	rest(info);
	// 	if (dead_philo(info))
	// 		break;
	// }
	return (data);
}