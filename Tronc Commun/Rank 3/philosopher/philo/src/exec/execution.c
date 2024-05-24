/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:33 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/24 14:12:56 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*tmp;

	tmp = (t_philo *)arg;
	printf("data = %d\n", tmp->data->num_of_meals);
	if (tmp->fork_l->fork == FALSE && tmp->fork_r.fork == FALSE)
	{
		// pthread_mutex_lock(&tmp->fork_l->fork_m);
		// pthread_mutex_lock(&tmp->fork_r.fork_m);
		// tmp->fork_l->fork = TRUE;
		// printf("Philo[%d] has taken the left fork\n", tmp->id);
		// tmp->fork_r.fork = TRUE;
		// printf("Philo[%d] has taken the right fork\n", tmp->id);
		// printf("Philo[%d] is eating\n", tmp->id);
		// tmp->meals++;
		// pthread_mutex_unlock(&tmp->fork_l->fork_m);
		// pthread_mutex_unlock(&tmp->fork_r.fork_m);
	}
	else
	{
		printf("Philo[%d] is thinking\n", tmp->id);
	}
	// tmp->fork_l->fork = FALSE;
	// tmp->fork_r.fork = FALSE;
	pthread_exit(EXIT_SUCCESS);
}

void	exec(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	if (philo->data->num_of_meals != -1)
	{
		while (i < philo->data->num_of_meals)
		{
			j = 0;
			while (j < philo->data->nb_philo)
			{
				pthread_create(&philo[j].thread, NULL, routine, (void *)&philo[j]);
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
	// print_philo(philo);
}
