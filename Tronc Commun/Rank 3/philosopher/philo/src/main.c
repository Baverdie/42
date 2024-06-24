/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:22 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/24 15:46:30 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (print_error(ERR_THREAD));
	if (pthread_join(data->tid[0], NULL))
		return (print_error(ERR_THREAD));
	ft_exit(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (check_input(av))
			return (print_error(ERR_ARGS2));
		if (init(ac, av, &data))
			return (1);
		if (data.nb_philo == 1)
			return (case_one(&data));
		if (thread_init(&data))
			return (1);
		ft_exit(&data);
	}
	else
		return (print_error(ERR_ARGS));
	return (0);
}
