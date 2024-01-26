/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:52:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/26 09:31:53 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	kill_mob(t_mlx *mlx, int y, int x)
{
	int	i;

	i = 0;
	while (i <= mlx->data->pos->nb_mobs)
	{
		if (mlx->data->mobs[i]->is_alive == 0)
		{
			i++;
			continue ;
		}
		if (mlx->data->mobs[i]->pos_x == x && mlx->data->mobs[i]->pos_y == y)
		{
			mlx->data->mobs[i]->is_alive = 0;
			mlx->data->map[y][x] = 'T';
			break ;
		}
		i++;
	}
	return (0);
}

int	is_avaible(t_data *data, int dir, int x, int y)
{
	int	neg;

	neg = 1;
	if (dir == 0 || dir == 1)
		neg = -1;
	if ((dir == 0 || dir == 2) && (x + 3 * neg <= 0 \
		|| x + 3 * neg >= data->nb_cols || data->map[y][x + 3 * neg] == 'E' \
		|| data->map[y][x + 3 * neg] == '1' \
		|| (data->map[y][x + 2 * neg] == '1' \
		&& data->map[y][x + 1 * neg] == '1')))
		return (1);
	else if ((dir == 1 || dir == 3) && (y + 3 * neg <= 0 \
		|| y + 3 * neg >= data->nb_rows - 1 || data->map[y + 3 * neg][x] == 'E' \
		|| data->map[y + 3 * neg][x] == '1' \
		|| (data->map[y + 2 * neg][x] == '1' \
		&& data->map[y + 1 * neg][x] == '1')))
		return (1);
	return (0);
}

int	check_score(t_data *data, int dir, int x, int y)
{
	int	scores;
	int	i;
	int	neg;

	i = 1;
	scores = 0;
	neg = 1;
	if (dir == 0 || dir == 1)
		neg = -1;
	if (is_avaible(data, dir, x, y))
		return (-1);
	while (i <= 3)
	{
		if ((dir == 0 || dir == 2) && x + i * neg > 0 \
			&& x + i * neg < data->nb_cols)
			scores += add_score_x(data, i, x + i * neg, y);
		if ((dir == 1 || dir == 3) && y + i * neg > 0 \
			&& y + i * neg < data->nb_rows - 1)
			scores += add_score_y(data, i, x, y + i * neg);
		i++;
	}
	return (scores);
}

int	init_scores(t_mlx *mlx, int scores[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		scores[i] = check_score(mlx->data, i, \
		mlx->data->pos->player_col, mlx->data->pos->player_row);
		i++;
	}
	return (*scores);
}

int	check_best_dir(t_mlx *mlx)
{
	int	best_dir;
	int	best_score;
	int	dir;
	int	scores[4];

	dir = 0;
	*scores = init_scores(mlx, scores);
	best_score = scores[dir];
	best_dir = dir;
	while (dir < 4)
	{
		if (scores[dir] > best_score && scores[dir] > -1)
		{
			best_score = scores[dir];
			best_dir = dir;
		}
		dir++;
	}
	if (best_score > 0)
		mlx->score += best_score;
	if (best_score >= 5)
		ft_print_score(mlx, best_score / 10);
	return (best_dir);
}
