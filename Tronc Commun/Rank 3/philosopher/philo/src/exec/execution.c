/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:33 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/23 16:24:52 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*tmp;
	
	tmp = (t_philo *)arg;
	if (tmp->fork_l->fork == FALSE && tmp->fork_r.fork == FALSE)
	{
		// pthread_mutex_lock(&tmp->fork_r.fork_m);
		tmp->fork_r.fork++;
		// pthread_mutex_unlock(&tmp->fork_r.fork_m);
		sleep(1);
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
