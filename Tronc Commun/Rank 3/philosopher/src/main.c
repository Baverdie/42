/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:22 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/28 17:19:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init(int ac, char **av)
{
	t_philo		*philo;
	long long	tmp;
	int			i;

	i = 0;
	tmp = ft_atoll(av[1]);
	if (tmp < 0 || tmp > 2147483647 || ft_strlen(av[1]) > 11)
		return (FALSE);
	philo = ft_calloc(tmp, sizeof(t_philo));
	if (!parse_args(ac, av, philo, (int)tmp))
	{
		free(philo);
		return (FALSE);
	}
	while (i < tmp)
	{
		ft_printf("id: %d\n", philo[i].id);
		i++;
	}
	free(philo);
	return (TRUE);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (!init(ac, av))
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	else
		ft_printf("Error\n");
	return (0);
}
