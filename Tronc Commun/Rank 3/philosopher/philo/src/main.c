/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:22 by basverdi          #+#    #+#             */
/*   Updated: 2024/04/30 17:42:34 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init(int ac, char **av)
{
	t_data	*data;
	int			i;

	i = 0;
	data = ft_calloc(1, sizeof(t_data));
	if (parse_args(ac, av, data))
	{
		free(data);
		return (TRUE);
	}
	while (i < data->nb_philo)
	{
		printf("id: %d\n", data->philo[i]->id);
		i++;
	}
	free(data);
	return (FALSE);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (init(ac, av))
		{
			printf("Error\n");
			return (0);
		}
		printf("C'est ok\n");
	}
	else
		printf("Error\n");
	return (0);
}
