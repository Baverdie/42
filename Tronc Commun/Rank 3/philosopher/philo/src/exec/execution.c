/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:33 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/18 17:05:03 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*supervisor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->dead)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die + 1 && !philo->eating)
			print_status(DIED, philo);
		pthread_mutex_lock(&philo->data->lock);
		if (philo->count_meals == philo->data->nb_meals \
			&& philo->data->finished < philo->data->nb_philo)
		{
			philo->data->finished++;
			philo->count_meals++;
		}
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

void	eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(FORK, philo);
	pthread_mutex_lock(philo->r_fork);
	print_status(FORK, philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = TRUE;
	philo->time_to_die = get_time() + philo->data->time_to_die;
	print_status(EATING, philo);
	ft_usleep(philo->data->time_to_eat);
	philo->count_meals++;
	philo->eating = FALSE;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	print_status(SLEEPING, philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_to_die = philo->data->time_to_die + get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return (NULL);
	while (!philo->data->dead)
	{
		eat_sleep(philo);
		print_status(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return (NULL);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished == philo->data->nb_philo)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

t_bool	thread_init(t_data *data)
{
	int			i;
	pthread_t	t0;

	i = -1;
	data->start_time = get_time();
	if (data->nb_meals > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &data->philos[0]))
			return (print_error(ERR_THREAD));
	}
	while (++i < data->nb_philo)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (print_error(ERR_THREAD));
		usleep(100);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->tid[i], NULL))
			return (print_error(ERR_THREAD));
	}
	return (FALSE);
}
