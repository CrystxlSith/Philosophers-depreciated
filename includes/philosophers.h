/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:34:28 by crystal           #+#    #+#             */
/*   Updated: 2024/08/16 02:18:38 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
 #include <stdlib.h>

typedef struct s_philo
{
	long int	nb_times_eat;
	int		id;
	struct s_data	*data;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	
}	t_philo;
typedef struct s_data
{
	long int	nb;
	long int	t_eat;
	long int	t_die;
	long int	t_sleep;
	long int	m_eat;
	pthread_mutex_t	write_lock;
	t_philo		*philo;
}	t_data;

int	ft_isdigit(int c);
void	ft_error(char *str);
size_t	ft_strlen(const char *s);