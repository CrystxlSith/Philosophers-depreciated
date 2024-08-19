/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:54:29 by crystal           #+#    #+#             */
/*   Updated: 2024/08/19 14:41:36 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int dead_philo_monitoring(t_philo *philo)
{
    // Verrouillage pour éviter les conditions de course lors de l'accès à last_meal et à d'autres variables partagées
    pthread_mutex_lock(&(philo->data->dead_lock));

    // Calculer le temps écoulé depuis le dernier repas
    long int time_since_last_meal = get_current_time() - philo->last_meal;

    // Vérifier si ce temps dépasse le temps maximal sans manger (t_die)
    if (time_since_last_meal > philo->data->t_die)
    {
        // Déverrouiller avant de retourner car le philosophe est déclaré mort
        pthread_mutex_unlock(&(philo->data->dead_lock));
        return 1;  // Le philosophe est mort
    }

    // Déverrouiller si le philosophe n'est pas mort
    pthread_mutex_unlock(&(philo->data->dead_lock));
    return 0;  // Le philosophe est encore en vie
}

// int	philosopher_dead(t_philo *philo, long unsigned int time_to_die)
// {
// 	pthread_mutex_lock(&philo->data->eat_lock);
// 	if (get_current_time() - philo->last_meal > time_to_die && philo->eat == 0)
// 		return (pthread_mutex_unlock(&philo->data->eat_lock), 1);
// 	pthread_mutex_unlock(&philo->data->eat_lock);
// 	return (0);
// }

int	dead_one(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->nb)
	{
		if (dead_philo_monitoring(&philo[i]))
		{
			ft_print("is dead !! 👻\n", philo, philo->id);
			philo[i].data->dead = 1;
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