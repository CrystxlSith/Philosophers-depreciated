/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:24:29 by crystal           #+#    #+#             */
/*   Updated: 2024/08/16 16:11:55 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	*routine(void *data)
{
	printf("Philosopher preparing to sit\n");
	sleep(5);
	printf("Hmmm so good 🌭\n");
	return NULL;
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_times_eat = 0;
		data->philo[i].data = data;
		data->philo[i].dead = false;
		pthread_mutex_init(&(data->philo[i].r_fork), NULL);
		pthread_mutex_lock(&(data->philo[i].r_fork));
		pthread_mutex_unlock(&(data->philo[i].r_fork));
		if (pthread_create())
		i++;
	}
	i = 0;
	
}

int	init_data(t_data *data, char *argv[])
{
	data->nb = ft_atol(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->nb);
	data->t_die = ft_atol(argv[2]);
	data->t_eat = ft_atol(argv[3]);
	data->t_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->m_eat = ft_atol(argv[5]);
}

void	check_arg(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	if (ac != 6 && ac != 5)
		ft_error("Invalid number of arguments\n");
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				ft_error("Invalid argument\n");	
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	check_arg(argc, argv);
	init_data(&data, argv);
	init_philo(&data);
	// pthread_t	philosophers[500];
	// int	i = 0;

	// while (i++ < 500)
	// 	pthread_create(philosophers + i, NULL, routine, NULL);
	// i = 0;
	// while (i++ < 500)
	// 	pthread_join(philosophers[i], NULL);
	free_destroy(&data);
	return 0;
}
