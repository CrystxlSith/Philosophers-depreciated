/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:24:29 by crystal           #+#    #+#             */
/*   Updated: 2024/08/15 23:33:13 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void	*routine(void *data)
{
	printf("Philosopher preparing to sit\n");
	sleep(5);
	printf("Hmmm so good\n");
	return NULL;
}

int main(void)
{
	pthread_t	philosophers[500];
	int	i = 0;

	while (i++ < 500)
		pthread_create(philosophers + i, NULL, routine, NULL);
	i = 0;
	while (i++ < 500)
		pthread_join(philosophers[i], NULL);
	
	return 0;
}
