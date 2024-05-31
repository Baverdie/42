/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:36:33 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/31 17:36:08 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	check_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data.death);
	if (philo->data.start)
		printf("%lld ms philo[%d] is_dead = %d\n", get_time(philo->data.start), philo->id + 1, philo->data.is_dead);
	else
		printf("Philo[%d] is_dead = %d\n", philo->id + 1, philo->data.is_dead);
	if (philo->data.is_dead)
		return (TRUE);
	pthread_mutex_unlock(&philo->data.death);
	return (FALSE);
}

t_bool	check_death(t_philo *philo)
{
	if (get_time(philo->data.start) > philo->data.time_to_die + 1)
	{
		pthread_mutex_lock(&philo->data.death);
		philo->data.is_dead = TRUE;
		print_status(philo->id, DIED, get_time(philo->data.start));
		pthread_mutex_unlock(&philo->data.death);
		return (TRUE);
	}
	return (FALSE);
}

void	eating(t_philo *tmp)
{
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
}

void	*routine(void *arg)
{
	t_philo	*tmp;

	tmp = (t_philo *)arg;
	if (tmp->id % 2)
		usleep(tmp->data.time_to_eat * 1000);
	while (!check_is_dead(tmp) && (tmp->data.num_of_meals == -1
			|| tmp->meals < tmp->data.num_of_meals))
	{
		if (check_is_dead(tmp))
			break;
		if (tmp->fork_l->fork || tmp->fork_r.fork)
			continue ;
		set_start(&tmp->data.start);
		eating(tmp);
		if (check_is_dead(tmp))
			break;
		print_status(tmp->id, SLEEPING, get_time(tmp->data.start));
		if (check_is_dead(tmp))
			break;
		usleep(tmp->data.time_to_sleep * 1000);
		if (check_death(tmp) || check_is_dead(tmp))
			break;
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
