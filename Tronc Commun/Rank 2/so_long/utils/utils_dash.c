/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:52:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/14 05:16:08 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_score(t_data *data, int dir)
{
	int	x;
	int	y;
	int	scores;
	int	i;

	i = 1;
	x = data->pos->player_col;
	y = data->pos->player_row;
	scores = 0;
	while (i <= 3)
	{
		if (dir == 0 && x - i > 0)
		{
			if(i < 3 && data->map[y][x - i] == 'M')
				scores += data->pos->ref_mob_score;
			if(data->map[y][x - i] == 'C')
				scores += data->pos->ref_col_score;
			if(i < 3 && data->map[y][x - i] == '1')
				scores += 1;
		}
		i++;
	}
	
	return (0);
}

int	check_dir(t_mlx *mlx)
{
	int	best_dir;
	int	best_score;
	int	dir;
	int	return_dir;
	int	**scores[4];

	dir = 0;
	while (dir < 4)
	{
		scores[dir] = check_score(mlx->data, dir);
		dir++;
	}
	dir = 0;
	best_score = scores[dir];
	best_dir = dir;
	return_dir = dir;
	while (dir < 4)
	{
		if (scores[dir] > best_score)
		{
			return_dir = best_dir;
			best_score = scores[dir];
			best_dir = dir;
		}
		dir++;
	}
	return (return_dir);
}
