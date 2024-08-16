/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:24:29 by crystal           #+#    #+#             */
/*   Updated: 2024/08/16 02:40:37 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

// void	*routine(void *data)
// {
// 	printf("Philosopher preparing to sit\n");
// 	sleep(5);
// 	printf("Hmmm so good 🌭\n");
// 	return NULL;
// }

int	init_data(t_data *data, char *argv[])
{
	data->nb = atoi(argv[1]);
	data->t_die = atoi(argv[2]) * 1e3;
	data->t_die = atoi(argv[3]) * 1e3;
	data->t_die = atoi(argv[4]) * 1e3;
	data->t_die = atoi(argv[5]);
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
	// pthread_t	philosophers[500];
	// int	i = 0;

	// while (i++ < 500)
	// 	pthread_create(philosophers + i, NULL, routine, NULL);
	// i = 0;
	// while (i++ < 500)
	// 	pthread_join(philosophers[i], NULL);
	return 0;
}
