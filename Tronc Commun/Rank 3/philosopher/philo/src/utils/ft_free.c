/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:37:12 by bastienverd       #+#    #+#             */
/*   Updated: 2024/05/14 14:38:20 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	ft_free_philo(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo)
	{
		while (i < data->nb_philo)
		{
			if (data->philo[i])
				free(data->philo[i]);
			i++;
		}
		free(data->philo);
	}
	return (TRUE);
}

t_bool	ft_free(t_data *data)
{
	if (data->philo)
		ft_free_philo(data);
	free(data);
	return (TRUE);
}