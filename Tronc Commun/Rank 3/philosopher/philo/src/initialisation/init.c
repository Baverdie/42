/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:18:26 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/18 16:44:24 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	init_data(int ac, char **av, t_data *data)
{
	if (ft_overflow("%ll %ll %ll %ll", av[1], av[2], av[3], av[4]) \
		|| ft_overflow("%i %i %i %i", av[1], av[2], av[3], av[4]))
		return (TRUE);
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		if (ft_overflow("%ll %i", av[5], av[5]))
			return (TRUE);
		data->nb_meals = ft_atoi(av[5]);
	}
	else
		data->nb_meals = -1;
	if (data->nb_philo <= 0 || data->nb_philo > 200 || data->time_to_die <= 0 \
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (TRUE);
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (FALSE);
}

t_bool	alloc(t_data *data)
{
	data->tid = ft_calloc(data->nb_philo, sizeof(pthread_t));
	if (!data->tid)
		return (print_error(ERR_MALLOC));
	data->forks = ft_calloc(data->nb_philo, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (print_error(ERR_MALLOC));
	data->philos = ft_calloc(data->nb_philo, sizeof(t_philo));
	if (!data->philos)
		return (print_error(ERR_MALLOC));
	return (FALSE);
}

t_bool	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[i].r_fork = &data->forks[0];
	data->philos[i].l_fork = &data->forks[data->nb_philo - 1];
	while (++i < data->nb_philo)
	{
		data->philos[i].r_fork = &data->forks[i];
		data->philos[i].l_fork = &data->forks[i - 1];
	}
	return (FALSE);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].count_meals = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

t_bool	init(int ac, char **av, t_data *data)
{
	if (init_data(ac, av, data))
		return (print_error(ERR_ARGS2));
	if (alloc(data))
	{
		ft_free_alloc(data);
		return (TRUE);
	}
	if (init_forks(data))
		return (TRUE);
	init_philos(data);
	return (FALSE);
}
