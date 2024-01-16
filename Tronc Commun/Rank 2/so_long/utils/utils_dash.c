/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:52:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/16 16:39:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_print_dash(t_mlx *mlx)
{
	if (mlx->data->dash_count == 2)
	{
		ft_printf("\033[1;31mDouble Kill +20 points !\033[0m\n");
		mlx->score += 20;
	}
	else if (mlx->data->dash_count == 3)
	{
		ft_printf("\033[1;31mTriple Kill +30 points !\033[0m\n");
		mlx->score += 30;
	}
	mlx->data->dash_count = 0;
	ft_printf("\033[1;37mScore : %d\n\033[0mMovements : %d\n", mlx->score, mlx->nb_move);
	return (0);
}

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
			data->dash_count++;
			break ;
		}
		i++;
	}
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
	if ((dir == 0 || dir == 2) && (x + 3 * neg <= 0 || x + 3 * neg >= data->nb_cols || data->map[y][x + 3 * neg] == 'E' || data->map[y][x + 3 * neg] == '1'))
		return (-1);
	else if ((dir == 1 || dir == 3) && (y + 3 * neg <= 0 || y + 3 * neg >= data->nb_rows - 1 || data->map[y + 3 * neg][x] == 'E' || data->map[y + 3 * neg][x] == '1'))
		return (-1);
	while (i <= 3)
	{
		if ((dir == 0 || dir == 2) && x + i * neg > 0 && x + i * neg < data->nb_cols)
		{
			if (i <= 3 && data->map[y][x + i * neg] == 'M')
				scores += data->pos->ref_mob_score;
			if (data->map[y][x + i * neg] == 'C')
				scores += data->pos->ref_col_score;
		}
		if ((dir == 1 || dir == 3) && y + i * neg > 0 && y + i * neg < data->nb_rows - 1)
		{
			if (i <= 3 && data->map[y + i * neg][x] == 'M')
				scores += data->pos->ref_mob_score;
			if (data->map[y + i * neg][x] == 'C')
				scores += data->pos->ref_col_score;
		}
		i++;
	}
	return (scores);
}

int	check_best_dir(t_mlx *mlx)
{
	int	best_dir;
	int	best_score;
	int	dir;
	int	scores[4];

	dir = 0;
	while (dir < 4)
	{
		scores[dir] = check_score(mlx->data, dir, mlx->data->pos->player_col, mlx->data->pos->player_row);
		dir++;
	}
	dir = 0;
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
	mlx->score += best_score;
	return(best_dir);
}
