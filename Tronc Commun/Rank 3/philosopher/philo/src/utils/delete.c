/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:59:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/23 15:16:47 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		printf("Philo[%d] L = %d\n", data->philo[i]->id, data->philo[i]->fork_l->fork);
		printf("Philo[%d] R = %d\n\n", data->philo[i]->id, data->philo[i]->fork_r.fork);
		i++;
	}
}