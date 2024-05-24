/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:33 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/24 10:59:10 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*tmp;

	tmp = (t_philo *)arg;
	if (tmp->fork_l->fork == FALSE && tmp->fork_r.fork == FALSE)
	{
		pthread_mutex_lock(&tmp->fork_l->fork_m);
		pthread_mutex_lock(&tmp->fork_r.fork_m);
		tmp->fork_l->fork = TRUE;
		printf("\e[1;31mPhilosopher \e[1;33m%d\e[1;31m has taken a fork\033[m\n", tmp->id + 1);
		tmp->fork_r.fork = TRUE;
		printf("\e[1;31mPhilosopher \e[1;33m%d\e[1;31m has taken a fork\033[m\n", tmp->id + 1);
		pthread_mutex_unlock(&tmp->fork_r.fork_m);
		pthread_mutex_unlock(&tmp->fork_l->fork_m);
		printf("\e[1;38;5;2mPhilosopher \e[1;33m%d\e[1;38;5;2m is eating\e[m\n", tmp->id + 1);
		usleep(data->time_to_eat * 1000);
	}
	pthread_exit(EXIT_SUCCESS);
}

void	exec(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->num_of_meals != -1)
	{
		while (i < data->num_of_meals)
		{
			j = 0;
			while (j < data->nb_philo)
			{
				pthread_create(&data->philo[j]->thread, NULL, routine, (void *)data->philo[j]);
				usleep(100);
				j++;
			}
			i++;
		}
	}
	else {
		while (1)
		{
			printf("OK\n");
		}
	}
	print_philo(data);
}
