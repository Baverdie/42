/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:33 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/27 18:01:51 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_philo	*tmp;

	tmp = (t_philo *)arg;
	if (tmp->id % 2)
		usleep(tmp->data.time_to_eat * 1000);
	while (!tmp->data.is_dead && (tmp->data.num_of_meals == -1
			|| tmp->meals < tmp->data.num_of_meals))
	{
		if (tmp->fork_l->fork || tmp->fork_r.fork)
			continue ;
		set_start(&tmp->data.start);
		pthread_mutex_lock(&tmp->fork_l->fork_m);
		pthread_mutex_lock(&tmp->fork_r.fork_m);
		tmp->fork_l->fork = TRUE;
		print_status(tmp->id, TAKE_FORKS, get_time(tmp->data.start));
		tmp->fork_r.fork = TRUE;
		print_status(tmp->id, TAKE_FORKS, get_time(tmp->data.start));
		print_status(tmp->id, EATING, get_time(tmp->data.start));
		tmp->meals++;
		usleep(tmp->data.time_to_eat * 1000);
		pthread_mutex_unlock(&tmp->fork_l->fork_m);
		pthread_mutex_unlock(&tmp->fork_r.fork_m);
		tmp->fork_l->fork = FALSE;
		tmp->fork_r.fork = FALSE;
		print_status(tmp->id, SLEEPING, get_time(tmp->data.start));
		usleep(tmp->data.time_to_sleep * 1000);
		if (get_time(tmp->data.start) > tmp->data.time_to_die + 1)
		{
			tmp->data.is_dead = TRUE;
			tmp->is_dead = TRUE;
			print_status(tmp->id, DIED, get_time(tmp->data.start));
			break ;
		}
		print_status(tmp->id, THINKING, get_time(tmp->data.start));
	}
	return (NULL);
}

void	exec(t_philo *philo)
{
	int	i;

	if (philo->data.nb_philo == 1)
	{
		print_status(0, DIED, 0);
		return ;
	}
	i = -1;
	while (++i < philo->data.nb_philo)
		pthread_create(&philo[i].thread, NULL, &routine, philo + i);
	while (i > 0)
		pthread_join(philo[--i].thread, NULL);
	print_philo(philo);
	print_status(0, FINISH, 0);
}
