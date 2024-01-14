/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:52:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/14 06:52:37 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	kill_mob(t_data *data, int y, int x)
{
	int	i;

	i = 0;
	while (i <= data->pos->nb_mobs)
	{
		if (data->mobs[i]->is_alive == 0)
		{
			i++;
			continue ;
		}
		if (data->mobs[i]->pos_x == x && data->mobs[i]->pos_y == y)
		{
			data->mobs[i]->is_alive = 0;
			data->map[y][x] = 'T';
			break ;
		}
		i++;
	}
	return (0);
}

int	check_score(t_data *data, int dir)
{
	int	x;
	int	y;
	int	scores;
	int	i;
	int	neg;

	i = 1;
	x = data->pos->player_col;
	y = data->pos->player_row;
	scores = 0;
	neg = 1;
	if (dir == 0 || dir == 1)
		neg = -1;
	while (i <= 3)
	{
		if ((dir == 0 || dir == 2) && x + i * neg > 0 && x + i * neg < data->nb_cols)
		{
			if(i <= 3 && data->map[y][x + i * neg] == 'M')
			{
				kill_mob(data, y, x + i * neg);
				scores += data->pos->ref_mob_score;
			}
			if(data->map[y][x + i * neg] == 'C')
				scores += data->pos->ref_col_score;
		}
		if ((dir == 1 || dir == 3) && y + i * neg > 0 && y + i * neg < data->nb_rows - 1)
		{
			if(i <= 3 && data->map[y + i * neg][x] == 'M')
			{
				kill_mob(data, y + i * neg, x);
				scores += data->pos->ref_mob_score;
			}
			if(data->map[y + i * neg][x] == 'C')
				scores += data->pos->ref_col_score;
		}
		i++;
	}
	return (scores);
}

int	check_dir(t_mlx *mlx)
{
	int	best_dir;
	int	best_score;
	int	dir;
	int	scores[4];

	dir = 0;
	while (dir < 4)
	{
		scores[dir] = check_score(mlx->data, dir);
		dir++;
	}
	dir = 0;
	best_score = scores[dir];
	best_dir = dir;
	while (dir < 4)
	{
		if (scores[dir] > best_score)
		{
			best_score = scores[dir];
			best_dir = dir;
		}
		dir++;
	}
	mlx->score += best_score;
	return(best_dir);
}
