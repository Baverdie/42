/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:04:49 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/28 17:18:24 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	init_philo(t_philo *philo, int count_philo, char **av)
{
	int	i;

	i = 0;
	while (i < count_philo)
	{
		philo[i].id = i + 1;
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			philo[i].num_of_meals = ft_atoi(av[5]);
		else
			philo[i].num_of_meals = -1;
		i++;
	}
	return (TRUE);
}

t_bool	parse_args(int ac, char **av, t_philo *philo, int count_philo)
{
	long long	tmp;
	int			i;

	i = 2;
	while (i <= 4)
	{
		tmp = ft_atoll(av[i]);
		if (tmp < 0 || tmp > 999999 || ft_strlen(av[i]) > 6)
			return (FALSE);
		i++;
	}
	if (ac == 6)
	{
		tmp = ft_atoll(av[i]);
		if (tmp < 0 || tmp > 2147483647 || ft_strlen(av[i]) > 6)
			return (FALSE);
	}
	init_philo(philo, count_philo, av);
	return (TRUE);
}
