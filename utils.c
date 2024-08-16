/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crystal <crystal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:20:39 by crystal           #+#    #+#             */
/*   Updated: 2024/08/16 20:34:13 by crystal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

size_t	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec) / 1000);
}

void	ft_usleep(size_t ms)
{
	size_t	starting;
	size_t	time_left;

	starting = get_current_time();
	while ((get_current_time() - starting) < ms)
	{
		time_left = ms - (get_current_time() - starting);
		if (time_left < 1)
			usleep(time_left * 1000);
		else
			usleep(500);
	}
}

void	ft_print(char *str, t_data *info)
{
	pthread_mutex_lock(&info->write_lock);
	if (str)
		printf("%s\n", str);
	pthread_mutex_unlock(&info->write_lock);	
}

int	ft_atol(const char *nptr)
{
	long	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r')
			i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}