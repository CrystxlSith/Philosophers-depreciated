/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:54:29 by crystal           #+#    #+#             */
/*   Updated: 2024/08/17 14:11:51 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	dead_one()

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