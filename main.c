/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopfeiff <jopfeiff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:24:29 by crystal           #+#    #+#             */
/*   Updated: 2024/10/02 10:22:23 by jopfeiff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	init_philo(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_times_eat = 0;
		data->philo[i].data = data;
		data->philo[i].eat = 1;
		data->philo[i].dead = &data->dead;
		data->philo[i].start_time = get_current_time();
		data->philo[i].last_meal = get_current_time();
		if (i == 0)
			data->philo[i].r_fork = &forks[data->nb - 1];
		else
			data->philo[i].r_fork = &forks[i - 1];
		i++;
	}
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
	else
		data->m_eat = -1;
	if (data->nb == 1)
		data->m_eat = 1;
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

void	init_forks(pthread_mutex_t *forks, long int nb)
{
	long int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	create_threads(t_data *data/*, pthread_mutex_t *forks*/)
{
	int	i;
	pthread_t	veryfier;

	i = 0;
	if (pthread_create(&veryfier, NULL, &monitoring, data->philo) != 0)
	{
		printf("Error thread monitoring\n");
		ft_error("Exiting...");
	}
	while (i < data->nb)
	{
		if (pthread_create(&(data->philo[i].thread), NULL, &routine, &(data->philo[i])))
		{
			printf("Error thread create num %d\n", i);
			ft_error("Exiting...");
		}
		i++;
	}
	if (pthread_join(veryfier, NULL) != 0)
		ft_error("Error joining verifier");
	i = -1;
	while (++i < data->nb)
		if (pthread_join(data->philo[i].thread, NULL))
			ft_error("Error joining threads");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	pthread_mutex_t	forks[200];

	check_arg(argc, argv);
	init_forks(forks, ft_atol(argv[1]));
	init_data(&data, argv);
	init_philo(&data, forks);
	create_threads(&data/*, forks*/);
	// printf("End of the simulation 🎮\n");
	free_destroy(&data);
	return 0;
}
