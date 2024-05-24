/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:22 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/24 15:26:40 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data.nb_philo)
	{
		philo[i].fork_r.fork = FALSE;
		pthread_mutex_init(&philo[i].fork_r.fork_m, NULL);
		if (i == 0)
			philo[i].fork_l = &philo[philo->data.nb_philo - 1].fork_r;
		else
			philo[i].fork_l = &philo[i - 1].fork_r;
		i++;
	}
	return (FALSE);
}

t_bool	init(int ac, char **av, t_philo *philo)
{
	if (parse_args(ac, av, philo))
		return (TRUE);
	if (init_forks(philo))
		return (TRUE);
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ft_overflow("%ll %i", av[1], av[1]))
		return (print_error("Error\n"));
	philo = ft_calloc(ft_atoi(av[1]), sizeof(t_philo));
	if (ac == 5 || ac == 6)
	{
		if (init(ac, av, philo))
		{
			printf("Error\n");
			return (0);
		}
		exec(philo);
	}
	else
		printf("Error\n");
	return (0);
}
