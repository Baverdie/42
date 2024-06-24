/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:33 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/24 11:30:13 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_meals(t_philo *philo)
{
	if (philo->data->nb_meals != -1 && philo->count_meals == philo->data->nb_meals)
		philo->data->finished++;
}

t_bool	drop_forks(t_philo *philo)
{
	if (philo->id > philo->id % 2) {
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	if (philo->data->dead)
		return (TRUE);
	return (FALSE);
}

t_bool	taken_forks(t_philo *philo)
{
	if (philo->l_fork == philo->r_fork)
	{
		print_status(FORK, philo);
		print_status(DIED, philo);
		return (TRUE);
	}
	if (philo->id > philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(FORK, philo);
		pthread_mutex_lock(philo->l_fork);
		print_status(FORK, philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(FORK, philo);
		pthread_mutex_lock(philo->r_fork);
		print_status(FORK, philo);
	}
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->dead)
	{
		pthread_mutex_unlock(&philo->data->lock);
		drop_forks(philo);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (FALSE);
}

t_bool	eat(t_philo *philo)
{
	int	time_to_die;
	int	time_to_eat;

	time_to_die = philo->data->time_to_die;
	time_to_eat = philo->data->time_to_eat;
	print_status(EATING, philo);
	while (time_to_eat > 0)
	{
		ft_usleep(10);
		pthread_mutex_lock(&philo->data->lock);
		if (time_to_die < time_to_eat || philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->lock);
			if (time_to_die < time_to_eat)
				print_status(DIED, philo);
			drop_forks(philo);
			return (TRUE);
		}
		pthread_mutex_unlock(&philo->data->lock);
		time_to_eat -= 10;
		time_to_die -= 10;
	}
	philo->count_meals++;
	if (philo->data->nb_meals != -1 && philo->count_meals == philo->data->nb_meals)
		philo->data->finished += 1;
	return (FALSE);
}

t_bool	ft_sleep(t_philo *philo, int time_to_die)
{
	int	time_to_sleep;

	time_to_sleep = philo->data->time_to_sleep;
	print_status(SLEEPING, philo);
	while (time_to_sleep > 0)
	{
		ft_usleep(10);
		pthread_mutex_lock(&philo->data->lock);
		if (time_to_die - (int)philo->data->time_to_eat < time_to_sleep \
			|| philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->lock);
			if (time_to_die - (int)philo->data->time_to_eat < time_to_sleep)
				print_status(DIED, philo);
			return (TRUE);
		}
		pthread_mutex_unlock(&philo->data->lock);
		time_to_sleep -= 10;
		time_to_die -= 10;
	}
	return (FALSE);
}

t_bool	think(t_philo *philo, int time_to_die)
{
	int	time_to_sleep;
	int	time_to_eat;
	int	time_to_think;

	time_to_sleep = philo->data->time_to_sleep;
	time_to_eat = philo->data->time_to_eat;
	time_to_think = time_to_eat - time_to_sleep;
	print_status(THINKING, philo);
	while (time_to_think > 0)
	{
		pthread_mutex_lock(&philo->data->lock);
		if (time_to_think + time_to_eat + time_to_sleep > time_to_die \
			|| philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->lock);
			if (time_to_think + time_to_eat + time_to_sleep > time_to_die)
				print_status(DIED, philo);
			return (TRUE);
		}
		pthread_mutex_unlock(&philo->data->lock);
		ft_usleep(10);
		time_to_think -= 10;
	}
	return (FALSE);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_to_die = philo->data->time_to_die + get_time();
	while (!philo->data->dead)
	{
		if (taken_forks(philo))
			return (NULL);
		if (eat(philo))
			return (NULL);
		if (drop_forks(philo))
			return (NULL);
		if (ft_sleep(philo, philo->data->time_to_die))
			return (NULL);
		if (think(philo, philo->data->time_to_die))
			return (NULL);
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->finished == philo->data->nb_philo)
		{
			pthread_mutex_unlock(&philo->data->lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->lock);
	}
	return (NULL);
}

t_bool	thread_init(t_data *data)
{
	int			i;

	data->start_time = get_time();
	i = -1;
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
