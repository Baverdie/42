/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:59:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/24 12:53:31 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		printf("Philo[%d] L = %d\n", philo[i].id, philo[i].fork_l->fork);
		printf("Philo[%d] R = %d\n\n", philo[i].id, philo[i].fork_r.fork);
		i++;
	}
}