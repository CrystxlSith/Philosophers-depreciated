/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:34:28 by crystal           #+#    #+#             */
/*   Updated: 2024/10/02 15:15:27 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct s_philo
{
	long int	nb_times_eat;
	size_t		last_meal;
	size_t		start_time;
	int		id;
	int		*dead;
	int		eat;
	struct s_data	*data;
	pthread_t	thread;
	// pthread_mutex_t	*eat_lock;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	
}	t_philo;

typedef struct s_data
{
	long int	nb;
	int		dead;

	unsigned int	t_eat;
	unsigned int	t_die;
	unsigned int	t_sleep;
	int	m_eat;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	eat_lock;
	t_philo		*philo;
}	t_data;

int	ft_isdigit(int c);
void	ft_error(char *str);
size_t	ft_strlen(const char *s);
void ft_print_eat(char *str, t_philo *info);
int	ft_atol(const char *nptr);
void	free_destroy(t_data *data);
void	ft_print(char *str, t_philo *info, int id);
void	*routine(void *data);
size_t	get_current_time(void);
int	dead_philo(t_philo *info);
void	*monitoring(void *data);
void	ft_usleep(size_t ms);