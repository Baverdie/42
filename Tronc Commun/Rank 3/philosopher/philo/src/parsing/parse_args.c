/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:04:49 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/24 14:11:46 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	init_philo(t_philo *philo, char **av)
{
	int	i;

	i = 0;
	philo->data->nb_philo = ft_atoi(av[1]);
	philo->data->time_to_eat = ft_atoi(av[3]);
	philo->data->time_to_die = ft_atoi(av[2]);
	philo->data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->data->num_of_meals = ft_atoi(av[5]);
	else
		philo->data->num_of_meals = -1;
	while (i < philo->data->nb_philo)
	{
		philo[i].id = i;
		philo[i].meals = 0;
		philo[i].die = 0;
		philo[i].data = philo->data;
		i++;
	}
	return (FALSE);
}

t_bool	parse_args(int ac, char **av, t_philo *philo)
{
	long long	tmp;
	int			i;

	i = 1;
	philo->data = ft_calloc(1, sizeof(t_data));
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
	return (init_philo(philo, av));
}
