/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:11:25 by babonnet          #+#    #+#             */
/*   Updated: 2024/07/13 17:28:32 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>

void	check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->nb_meals != -1
		&& philo->count_meals == philo->data->nb_meals)
		philo->data->finished++;
	pthread_mutex_unlock(&philo->data->lock);
}

t_bool	drop_forks(t_philo *philo)
{
	if (philo->id > philo->id % 2)
	{
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

void	lock(t_philo *philo)
{
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
}

t_bool	taken_forks(t_philo *philo)
{
	if (philo->l_fork == philo->r_fork)
	{
		print_status(FORK, philo);
		print_status(DIED, philo);
		return (TRUE);
	}
	if (!(philo->id % 2) && !philo->count_meals)
		ft_usleep(philo->data->time_to_eat);
	lock(philo);
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
