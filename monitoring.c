/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:54:29 by crystal           #+#    #+#             */
/*   Updated: 2024/08/17 14:34:12 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	dead_philo_monitoring(t_philo *philo, size_t t2d)
{
	
}

int	dead_one(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->nb)
	{
		if (dead_philo_monitoring(&philo[i]))
		{
			pthread_mutex_lock(&philo[0].dead_lock);
			ft_print("is dead !! 👻",&philo[i], &philo[i].id);
			philo->dead = 1;
			pthread_mutex_unlock(&philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitoring(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	while (1)
	{
		if (dead_one(philo) == 1)
			break ;
	}
	return (data);
}