/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:48:40 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/23 12:59:31 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_dash_right(t_mlx *mlx, char **map, int x, int y)
{
	int	i;

	i = 1;
	if (!(x + 3 < mlx->data->nb_cols
			&& ((map[y][x + 1] != '1' || map[y][x + 2] != '1')
		&& !(map[y][x + 1] == '1' && map[y][x + 2] == '1'))
		&& map[y][x + 3] != '1'))
		return (1);
	while (i <= 3)
	{
		if (map[y][x + i] == 'C')
			mlx->nb_col++;
		if (map[y][x + i] == 'C')
			map[y][x + i] = '0';
		if (map[y][x + i] == 'M')
			kill_mob(mlx, y, x + i);
		if (map[y][x + 3] == 'E' && mlx->nb_col == mlx->data->pos->obj)
			mlx_loop_end(mlx->mlx);
		if (i == 3 && map[y][x + i] != 'E')
			mlx->data->pos->player_col = x + i;
		mlx->dir_player = 2;
		ft_map(mlx);
		i++;
	}
	return (0);
}

int	ft_dash_left(t_mlx *mlx, char **map, int x, int y)
{
	int	i;

	i = 1;
	if (!(x - 3 > 0 && ((map[y][x - 1] != '1' || map[y][x - 2] != '1')
		&& !(map[y][x - 1] == '1' && map[y][x - 2] == '1'))
		&& map[y][x - 3] != '1'))
		return (1);
	while (i <= 3)
	{
		if (map[y][x - i] == 'C')
			mlx->nb_col++;
		if (map[y][x - i] == 'C')
			map[y][x - i] = '0';
		if (map[y][x - i] == 'M')
			kill_mob(mlx, y, x - i);
		if (map[y][x - 3] == 'E' && mlx->nb_col == mlx->data->pos->obj)
			mlx_loop_end(mlx->mlx);
		if (i == 3 && map[y][x - i] != 'E')
			mlx->data->pos->player_col = x - i;
		mlx->dir_player = 0;
		ft_map(mlx);
		i++;
	}
	return (0);
}

int	ft_dash_top(t_mlx *mlx, char **map, int x, int y)
{
	int	i;

	i = 1;
	if (!(y - 3 > 0 && ((map[y - 2][x] != '1' || map[y - 1][x] != '1')
		&& !(map[y - 1][x] == '1' && map[y - 2][x] == '1'))
		&& map[y - 3][x] != '1'))
		return (1);
	while (i <= 3)
	{
		if (map[y - i][x] == 'C')
		{
			mlx->nb_col++;
			map[y - i][x] = '0';
		}
		if (map[y - i][x] == 'M')
			kill_mob(mlx, y - i, x);
		if (map[y - 3][x] == 'E' && mlx->nb_col == mlx->data->pos->obj)
			mlx_loop_end(mlx->mlx);
		if (i == 3 && map[y - i][x] != 'E')
			mlx->data->pos->player_row = y - i;
		mlx->dir_player = 1;
		ft_map(mlx);
		i++;
	}
	return (0);
}

int	ft_dash_bottom(t_mlx *mlx, char **map, int x, int y)
{
	int	i;

	i = 1;
	if (!(y + 3 < mlx->data->nb_rows \
		&& ((map[y + 2][x] != '1' || map[y + 1][x] != '1')
		&& !(map[y + 1][x] == '1' && map[y + 2][x] == '1'))
		&& map[y + 3][x] != '1'))
		return (1);
	while (i <= 3)
	{
		if (map[y + i][x] == 'C')
			mlx->nb_col++;
		if (map[y + i][x] == 'C')
			map[y + i][x] = '0';
		if (map[y + i][x] == 'M')
			kill_mob(mlx, y + i, x);
		if (map[y + 3][x] == 'E' && mlx->nb_col == mlx->data->pos->obj)
			mlx_loop_end(mlx->mlx);
		if (i == 3 && map[y + i][x] != 'E')
			mlx->data->pos->player_row = y + i;
		mlx->dir_player = 3;
		ft_map(mlx);
		i++;
	}
	return (0);
}

int	ft_dash(t_mlx *mlx)
{
	int	dir;
	int	new_dir;
	int	i;

	i = 1;
	new_dir = 0;
	dir = check_best_dir(mlx);
	if (dir == 0)
		ft_dash_left(mlx, mlx->data->map, \
		mlx->data->pos->player_col, mlx->data->pos->player_row);
	if (dir == 1)
		ft_dash_top(mlx, mlx->data->map, \
		mlx->data->pos->player_col, mlx->data->pos->player_row);
	if (dir == 2)
		ft_dash_right(mlx, mlx->data->map, \
		mlx->data->pos->player_col, mlx->data->pos->player_row);
	if (dir == 3)
		ft_dash_bottom(mlx, mlx->data->map, \
		mlx->data->pos->player_col, mlx->data->pos->player_row);
	mlx->nb_move += 1;
	ft_printf("Movements : %d\n", mlx->nb_move);
	return (0);
}
