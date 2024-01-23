/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:54:38 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/23 13:06:19 by basverdi         ###   ########.fr       */
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
	data->mobs[counter_mob]->tombstone = 0;
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

int	lateral(t_data *data, t_mob *mob, int rd)
{
	if (rd == 0)
	{
		if (mob->pos_x > 0 && (data->map[mob->pos_y][mob->pos_x - 1] != 'M'
			&& data->map[mob->pos_y][mob->pos_x - 1] != '1'
			&& data->map[mob->pos_y][mob->pos_x - 1] != 'E'
			&& data->map[mob->pos_y][mob->pos_x - 1] != 'C'))
			return (rd);
		rd++;
	}
	if (rd == 2)
	{
		if (mob->pos_x < data->nb_cols
			&& (data->map[mob->pos_y][mob->pos_x + 1] != 'M'
			&& data->map[mob->pos_y][mob->pos_x + 1] != '1'
			&& data->map[mob->pos_y][mob->pos_x + 1] != 'E'
			&& data->map[mob->pos_y][mob->pos_x + 1] != 'C'))
			return (rd);
		rd++;
	}
	return (rd);
}

int	vertical(t_data *data, t_mob *mob, int rd)
{
	if (rd == 1)
	{
		if (mob->pos_y > 0 && (data->map[mob->pos_y - 1][mob->pos_x] != 'M'
			&& data->map[mob->pos_y - 1][mob->pos_x] != '1'
			&& data->map[mob->pos_y - 1][mob->pos_x] != 'E'
			&& data->map[mob->pos_y - 1][mob->pos_x] != 'C'))
			return (rd);
		rd++;
	}
	if (rd == 3)
	{
		if (mob->pos_y < data->nb_rows
			&& (data->map[mob->pos_y + 1][mob->pos_x] != 'M'
			&& data->map[mob->pos_y + 1][mob->pos_x] != '1'
			&& data->map[mob->pos_y + 1][mob->pos_x] != 'E'
			&& data->map[mob->pos_y + 1][mob->pos_x] != 'C'))
			return (rd);
		rd = 0;
	}
	return (rd);
}

void	print_map_mob(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (move_mobs(mlx->data))
		mlx_loop_end(mlx->mlx);
	while (mlx->data->map[i])
	{
		j = 0;
		while (mlx->data->map[i][j])
		{
			if (mlx->data->map[i][j] == 'M')
				display_mob(mlx, i, j);
			j++;
		}
		i++;
	}
	mlx->nb_frames = 0;
}
