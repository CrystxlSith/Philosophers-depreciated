/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:54:29 by crystal           #+#    #+#             */
/*   Updated: 2024/10/01 14:18:26 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int dead_philo_monitoring(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_lock);
	if (get_current_time() - philo->last_meal > philo->data->t_die && philo->eat == 0)
	{
		pthread_mutex_unlock(&philo->data->eat_lock);	
		return (1);
	}
	pthread_mutex_unlock(&philo->data->eat_lock);	
	return (0);
// 	pthread_mutex_lock(&(philo->data->dead_lock));
// 	long int time_since_last_meal;
	
// 	time_since_last_meal = get_current_time() - philo->last_meal;
// 	if (time_since_last_meal > philo->data->t_die)
// 	{
// 		pthread_mutex_unlock(&(philo->data->dead_lock));
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&(philo->data->dead_lock));
// 	return (0);
}

int	dead_one(t_philo *philo)
{
	int	i;

	i = 0;
	if (!philo || !philo->data)
	{
	  fprintf(stderr, "Null pointer detected in dead_one()\n");
 	   exit(1);
	}
	while (i < philo[0].data->nb)
	{
		if (dead_philo_monitoring(&philo[i]) || (philo[i].nb_times_eat == philo[i].data->m_eat))
		{
			ft_print("is died", &philo[i], philo[i].id);
			pthread_mutex_lock(&philo[0].data->dead_lock);
			philo[0].data->dead = 1;
			pthread_mutex_unlock(&philo[0].data->dead_lock);
				return (1);
			
		}
		i++;
	}
	return (0);
}

int		eat_reached(t_philo *philo)
{
	int	complete_meals;
	int	i;

	i = 0;
	complete_meals = 0;
	while (i < philo->data->nb)
	{
		pthread_mutex_lock(&philo[i].data->eat_lock);
		if (philo->nb_times_eat == philo->data->m_eat)
			complete_meals += 1;
		pthread_mutex_unlock(&philo[i].data->eat_lock);
		i++;
	}
	if (complete_meals == philo->data->nb)
	{
		pthread_mutex_lock(&philo[0].data->dead_lock);
		philo[0].data->dead = 1;
		pthread_mutex_unlock(&philo[0].data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitoring(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	while (1)
	{
		if (dead_one(philo) || eat_reached(philo))
			break ;
	}
	return (data);
}