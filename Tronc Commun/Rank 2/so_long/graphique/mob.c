/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:09:23 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/14 01:38:57 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	pos_mob(t_data *data)
{
	int	counter_mob;
	int	i;
	int	j;

	data->mobs = ft_calloc(sizeof(t_mob *), count_mob(data));
	data->pos->nb_mobs = count_mob(data);
	if (data->mobs == NULL)
		return (0);
	i = 0;
	counter_mob = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'M')
			{
				data->mobs[counter_mob] = ft_calloc(sizeof(t_mob), 1);
				data->mobs[counter_mob]->pos_x = j;
				data->mobs[counter_mob]->pos_y = i;
				data->mobs[counter_mob]->initial_x = j;
				data->mobs[counter_mob]->initial_y = i;
				counter_mob++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_rand_move(t_data *data, t_mob *mob, int rd)
{
	if (rd == 0)
		if (mob->pos_x > 0 && data->map[mob->pos_y][mob->pos_x - 1] == '1' && data->map[mob->pos_y][mob->pos_x + 1] == 'E' && data->map[mob->pos_y][mob->pos_x + 1] == 'C')
			return (1);
	if (rd == 1)
		if (mob->pos_y > 0 && data->map[mob->pos_y - 1][mob->pos_x] == '1' && data->map[mob->pos_y][mob->pos_x + 1] == 'E' && data->map[mob->pos_y][mob->pos_x + 1] == 'C')
			return (1);
	if (rd == 2)
		if (mob->pos_x < data->nb_cols && data->map[mob->pos_y][mob->pos_x + 1] == '1' && data->map[mob->pos_y][mob->pos_x + 1] == 'E' && data->map[mob->pos_y][mob->pos_x + 1] == 'C')
			return (1);
	if (rd == 3)
		if (mob->pos_y < data->nb_rows && data->map[mob->pos_y + 1][mob->pos_x] == '1' && data->map[mob->pos_y + 1][mob->pos_x] == 'E' && data->map[mob->pos_y + 1][mob->pos_x] == 'C')
			return (1);
	return (0);
}

int	move_mobs(t_data *data)
{
	int	i;
	int	rd;

	i = 0;
	rd = -1;
	while (i < data->pos->nb_mobs)
	{
		while (rd == -1 || ft_check_rand_move(data, data->mobs[i], rd))
		{
			srand(time(NULL));
			rd = rand() % 4;
		}
		define_new_mob_pos(data, rd);
		i++;
	}
}
