/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:24:29 by crystal           #+#    #+#             */
/*   Updated: 2024/08/16 02:29:45 by crystal          ###   ########.fr       */
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
	printf("argc = %d\n", argc);
	check_arg(argc, argv);
	// pthread_t	philosophers[500];
	// int	i = 0;

	// while (i++ < 500)
	// 	pthread_create(philosophers + i, NULL, routine, NULL);
	// i = 0;
	// while (i++ < 500)
	// 	pthread_join(philosophers[i], NULL);
	return 0;
}
