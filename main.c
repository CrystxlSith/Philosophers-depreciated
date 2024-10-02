/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:24:29 by crystal           #+#    #+#             */
/*   Updated: 2024/10/02 11:56:34 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void init_philo(t_data *data) {
    int i;
    pthread_t veryfier;

    i = 0;
    while (i < data->nb) {
        data->philo[i].id = i + 1;
        data->philo[i].nb_times_eat = 0;
        data->philo[i].data = data;
        data->philo[i].eat = 1;
        data->philo[i].dead = &data->dead;
        data->philo[i].start_time = get_current_time();
        data->philo[i].last_meal = get_current_time();
        if (i == data->nb - 1)
            data->philo[i].r_fork = &data->philo[0].l_fork;
        else
            data->philo[i].r_fork = &data->philo[i + 1].l_fork;
        pthread_mutex_init(&data->philo[i].l_fork, NULL);
        if (pthread_create(&(data->philo[i].thread), NULL, &routine, &(data->philo[i]))) {
            printf("Error thread creat num %d\n", i);
            ft_error("Exiting...");
        }
        i++;
    }
    if (pthread_create(&veryfier, NULL, &monitoring, data->philo) != 0) {
        printf("Error thread monitoring\n");
        ft_error("Exiting...");
    }
    if (pthread_join(veryfier, NULL) != 0)
        ft_error("Error joining veryfier");
    i = -1;
    while (++i < data->nb)
        if (pthread_join(data->philo[i].thread, NULL))
            ft_error("Errror joining threads");
}

void	init_data(t_data *data, char *argv[])
{
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->nb = ft_atol(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->nb);
	data->t_die = ft_atol(argv[2]);
	data->t_eat = ft_atol(argv[3]);
	data->t_sleep = ft_atol(argv[4]);
	data->dead = 0;
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
	printf("End of the simulation 🎮\n");
	// free_destroy(&data);
	return 0;
}
