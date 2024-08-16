/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:24 by crystal           #+#    #+#             */
/*   Updated: 2024/08/16 20:38:09 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	think(t_data *data)
{
	
}

int	dead_philo(t_data *info)
{
	pthread_mutex_lock(&info->dead_lock);
	if (info->dead)
	{
		pthread_mutex_unlock(&info->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->dead_lock);
	return (0);
}

void	*routine(void *data)
{
	int	i;
	t_data *info;
	
	info = (t_data *)data;
	while (!dead_philo(info))
	{
		think(info);
		sleep(info);
		i++;	
	}
	return (NULL);
}