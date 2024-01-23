/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:52:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/23 13:07:11 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_print_score(t_mlx *mlx, int nb_kill)
{
	if (nb_kill == 1)
		ft_printf("\033[1;31mOne Kill !\033[0m\n");
	if (nb_kill == 2)
	{
		ft_printf("\033[1;31mDouble Kill +10 points !\033[0m\n");
		mlx->score += 10;
	}
	else if (nb_kill == 3)
	{
		ft_printf("\033[1;31mTriple Kill +50 points !\033[0m\n");
		mlx->score += 50;
	}
	ft_printf("\033[1;37mScore : %d\033[0m\n", mlx->score);
	return (0);
}

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
	if ((dir == 0 || dir == 2) && (x + 3 * neg <= 0 \
		|| x + 3 * neg >= data->nb_cols || data->map[y][x + 3 * neg] == 'E' \
		|| data->map[y][x + 3 * neg] == '1'))
		return (-1);
	else if ((dir == 1 || dir == 3) && (y + 3 * neg <= 0 \
		|| y + 3 * neg >= data->nb_rows - 1 || data->map[y + 3 * neg][x] == 'E' \
		|| data->map[y + 3 * neg][x] == '1'))
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

int	check_best_dir(t_mlx *mlx)
{
	int	best_dir;
	int	best_score;
	int	dir;
	int	scores[4];

	dir = 0;
	while (dir < 4)
	{
		scores[dir] = check_score(mlx->data, dir, \
		mlx->data->pos->player_col, mlx->data->pos->player_row);
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
	if (best_score > 10)
		ft_print_score(mlx, best_score / 10);
	return (best_dir);
}
