/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:27:09 by crystal           #+#    #+#             */
/*   Updated: 2024/10/02 10:41:47 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	free_destroy(t_data *data)
{
	long int	i;

	i = 0;
	while(i < data->nb)
	{
		// pthread_mutex_destroy(&(data->philo[i].l_fork));
		pthread_mutex_destroy(data->philo[i].r_fork);
		i++;
	}
	pthread_mutex_destroy(&data->eat_lock);
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->write_lock);
	free(data->philo);
}