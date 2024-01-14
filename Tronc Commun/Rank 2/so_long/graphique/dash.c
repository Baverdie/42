/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:48:40 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/14 04:58:11 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_dash_right(t_mlx *mlx)
{
	char **map;
	int	x;
	int	y;
	int	i;
	
	map = mlx->data->map;
	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	i = 1;
	if (x + 3 < mlx->data->nb_cols && map[y][x + 1] != '1' && map[y][x + 2] != '1' && map[y][x + 3] != '1')
	{
		while (i <= 3)
		{
			if (map[y][x + i] == 'C')
				mlx->nb_col++;
			if (map[y][x + i] == 'E' && mlx->nb_col == mlx->data->pos->obj)
				mlx_loop_end(mlx->mlx);	
			if (i == 3 && map[y][x + i] != 'E')
				mlx->data->pos->player_col = x + i;
			ft_map(mlx);
			i++;
		}
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
	}
}

void	ft_dash_left(t_mlx *mlx)
{
	char **map;
	int	x;
	int	y;
	int	i;
	
	map = mlx->data->map;
	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	i = 1;
	if (x - 3 > 0 && map[y][x - 1] != '1' && map[y][x - 2] != '1' && map[y][x - 3] != '1')
	{
		while (i <= 3)
		{
			if (map[y][x - i] == 'C')
				mlx->nb_col++;
			if (map[y][x - i] == 'E' && mlx->nb_col == mlx->data->pos->obj)
				mlx_loop_end(mlx->mlx);	
			if (i == 3 && map[y][x - i] != 'E')
				mlx->data->pos->player_col = x - i;
			ft_map(mlx);
			i++;
		}
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
	}
}

void	ft_dash_top(t_mlx *mlx)
{
	char **map;
	int	x;
	int	y;
	int	i;
	
	map = mlx->data->map;
	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	i = 1;
	if (y - 3 > 0 && map[y - 1][x] != '1' && map[y - 2][x] != '1' && map[y - 3][x] != '1')
	{
		while (i <= 3)
		{
			if (map[y - i][x] == 'C')
				mlx->nb_col++;
			if (map[y - i][x] == 'E' && mlx->nb_col == mlx->data->pos->obj)
				mlx_loop_end(mlx->mlx);	
			if (i == 3 && map[y - i][x] != 'E')
				mlx->data->pos->player_row = y - i;
			ft_map(mlx);
			i++;
		}
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
	}
}

void	ft_dash_bottom(t_mlx *mlx)
{
	char **map;
	int	x;
	int	y;
	int	i;
	
	map = mlx->data->map;
	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	i = 1;
	if (y + 3 < mlx->data->nb_rows && map[y + 1][x] != '1' && map[y + 2][x] != '1' && map[y + 3][x] != '1')
	{
		while (i <= 3)
		{
			if (map[y + i][x] == 'C')
				mlx->nb_col++;
			if (map[y + i][x] == 'E' && mlx->nb_col == mlx->data->pos->obj)
				mlx_loop_end(mlx->mlx);	
			if (i == 3 && map[y + i][x] != 'E')
				mlx->data->pos->player_row = y + i;
			ft_map(mlx);
			i++;
		}
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
	}
}

int ft_dash(t_mlx *mlx)
{
	int	dir;

	dir = check_dir(mlx);
	if (dir == 0)
		ft_dash_left(mlx);
	if (dir == 1)
		ft_dash_top(mlx);
	if (dir == 2)
		ft_dash_right(mlx);
	if (dir == 3)
		ft_dash_bottom(mlx);
	return (0);
}