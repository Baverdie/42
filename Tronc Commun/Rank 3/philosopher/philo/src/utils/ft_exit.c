/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:37:12 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/20 17:44:59 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_free_alloc(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->lock);
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	free_philo(t_data *data, int status)
{
	int	i;

	i = 0;
	if (status == 1)
	{
		while (i < data->nb_philo)
		{
			// pthread_mutex_destroy(data->philos[i].r_fork);
			// pthread_mutex_destroy(data->philos[i].l_fork);
			i++;
		}
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].lock);
		// pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	free_philo(data, 1);
	ft_free_alloc(data);
}
