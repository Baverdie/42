/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:22 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/14 15:41:31 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i]->fork_r.fork = FALSE;
		if (i == 0)
			data->philo[i]->fork_l = &data->philo[data->nb_philo - 1]->fork_r;
		else
			data->philo[i]->fork_l = &data->philo[i - 1]->fork_r;
		i++;
	}
	return (FALSE);
}

t_bool	init(int ac, char **av, t_data *data)
{
	int			i;

	i = 0;
	if (parse_args(ac, av, data))
		return (TRUE);
	if (init_forks(data))
		return (TRUE);
	while (i < data->nb_philo)
	{
		printf("Fork Right philo[%d] = %d\n", i, data->philo[i]->fork_r.fork);
		printf("Fork Left philo[%d] = %d\n", i, data->philo[i]->fork_l->fork);
		i++;
	}
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_data *data;

	if (ac == 5 || ac == 6)
	{
		data = ft_calloc(1, sizeof(t_data));
		if (init(ac, av, data))
		{
			printf("Error\n");
			ft_free(data);
			return (0);
		}
		printf("C'est ok\n");
	}
	else
		printf("Error\n");
	return (0);
}
