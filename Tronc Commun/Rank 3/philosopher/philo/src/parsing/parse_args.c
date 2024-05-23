/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:04:49 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/14 14:38:00 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	init_philo(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->num_of_meals = ft_atoi(av[5]);
	else
		data->num_of_meals = -1;
	data->philo = ft_calloc(data->nb_philo, sizeof(t_philo*));
	if (!data->philo)
		return (ft_free_philo(data));
	while (i < data->nb_philo)
	{
		data->philo[i] = ft_calloc(i, sizeof(t_philo));
		if (!data->philo[i])
			return (ft_free_philo(data));
		data->philo[i]->id = i;
		i++;
	}
	return (FALSE);
}

t_bool	parse_args(int ac, char **av, t_data *data)
{
	long long	tmp;
	int			i;

	i = 1;
	if (ft_overflow("%ll %ll %ll %ll", av[1], av[2], av[3], av[4]))
		return (TRUE);
	while (i <= 4)
	{
		tmp = ft_atoll(av[i]);
		if (tmp < 0 || tmp > 999999 || ft_strlen(av[i]) > 6)
			return (TRUE);
		i++;
	}
	if (ac == 6)
	{
		ft_overflow("%ll", av[5]);
		tmp = ft_atoll(av[i]);
		if (tmp < 0 || tmp > 2147483647 || ft_strlen(av[i]) > 6)
			return (TRUE);
	}
	return (init_philo(data, av));
}
