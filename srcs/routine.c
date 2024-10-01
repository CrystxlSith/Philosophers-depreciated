/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:24 by crystal           #+#    #+#             */
/*   Updated: 2024/10/01 14:49:00 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	think_rest(t_philo *data)
{
	// if (dead_philo(data))
	// 	return ;
	ft_print("is thinking", data, data->id);
	// if (dead_philo(data))
	// 	return ;
	ft_print("is sleeping", data, data->id);
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
int	eat(t_philo *info)
{
	pthread_mutex_lock(info->r_fork);
	ft_print("has taken a fork", info, info->id);
	if (info->data->nb == 1)
	{
		ft_usleep(info->data->t_die);
		info->nb_times_eat += 1;
		info->eat = 0;
		return (pthread_mutex_unlock(info->r_fork), 1);
	}
	pthread_mutex_lock(info->l_fork);
	ft_print("has taken a fork", info, info->id);
	info->eat = 1;
	ft_print("is eating", info, info->id);
	pthread_mutex_lock(&info->data->eat_lock);
	info->last_meal = get_current_time();
	info->nb_times_eat += 1;
	pthread_mutex_unlock(&info->data->eat_lock);
	ft_usleep(info->data->t_eat);
	info->eat = 0;
	pthread_mutex_unlock(info->l_fork);
	pthread_mutex_unlock(info->r_fork);
	return (0);
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
		if (eat(info) == 1)
			break ;
		think_rest(info);
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