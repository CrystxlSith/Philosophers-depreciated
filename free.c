/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:27:09 by crystal           #+#    #+#             */
/*   Updated: 2024/08/16 15:31:47 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	free_destroy(t_data *data)
{
	long int	i;

	i = 0;
	while(i < data->nb)
	{
		pthread_mutex_destroy(&(data->philo[i].r_fork));
		i++;
	}
	free(data->philo);
}