/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:54:38 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/18 12:35:01 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_mob(t_data *data, int counter_mob, int i, int j)
{
	data->mobs[counter_mob] = ft_calloc(sizeof(t_mob), 1);
	if (!data->mobs[counter_mob])
		return (1);
	data->mobs[counter_mob]->is_alive = 1;
	data->mobs[counter_mob]->id = counter_mob;
	data->mobs[counter_mob]->pos_x = j;
	data->mobs[counter_mob]->pos_y = i;
	data->mobs[counter_mob]->initial_x = j;
	data->mobs[counter_mob]->initial_y = i;
	return (0);
}

int	count_mob(t_data *data)
{
	int	counter_mob;
	int	i;
	int	j;

	i = 0;
	counter_mob = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'M')
				counter_mob++;
			j++;
		}
		i++;
	}
	return (counter_mob);
}
