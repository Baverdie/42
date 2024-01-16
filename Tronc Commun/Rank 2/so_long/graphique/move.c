/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:33:09 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/16 16:31:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_forward(t_mlx *mlx)
{
	int	x;
	int	y;
	int	obj;

	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	obj = mlx->data->pos->obj;
	if (mlx->data->map[y - 1][x] != '1' && (mlx->data->map[y - 1][x] != 'E' || mlx->nb_col == obj))
	{
		if (mlx->data->map[y - 1][x] == 'C')
		{
			mlx->nb_col++;
			mlx->data->map[y - 1][x] = '0';
			mlx->score += mlx->data->pos->ref_col_score;
			ft_printf("\033[1;37mScore : %d\n\033[0m", mlx->score);
		}
		if ((mlx->data->map[y - 1][x] == 'E' && mlx->nb_col == mlx->data->pos->obj) || mlx->data->map[y - 1][x] == 'M' || mlx->data->map[y - 1][x] == 'B')
			mlx_loop_end(mlx->mlx);
		mlx->data->pos->player_row--;
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
		ft_map(mlx);
	}
}

void	ft_backward(t_mlx *mlx)
{
	int	x;
	int	y;
	int	obj;

	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	obj = mlx->data->pos->obj;
	if (mlx->data->map[y + 1][x] != '1' && (mlx->data->map[y + 1][x] != 'E' || mlx->nb_col == obj))
	{
		if (mlx->data->map[y + 1][x] == 'C')
		{
			mlx->nb_col++;
			mlx->score += mlx->data->pos->ref_col_score;
			mlx->data->map[y + 1][x] = '0';
			ft_printf("\033[1;37mScore : %d\n\033[0m", mlx->score);
		}
		if ((mlx->data->map[y + 1][x] == 'E' && mlx->nb_col == mlx->data->pos->obj) || mlx->data->map[y + 1][x] == 'M' || mlx->data->map[y + 1][x] == 'B')
			mlx_loop_end(mlx->mlx);
		mlx->data->pos->player_row++;
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
		ft_map(mlx);
	}
}

void	ft_right(t_mlx *mlx)
{
	int	x;
	int	y;
	int	obj;

	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	obj = mlx->data->pos->obj;
	if (mlx->data->map[y][x + 1] != '1' && (mlx->data->map[y][x + 1] != 'E' || mlx->nb_col == obj))
	{
		if (mlx->data->map[y][x + 1] == 'C')
		{
			mlx->nb_col++;
			mlx->score += mlx->data->pos->ref_col_score;
			mlx->data->map[y][x + 1] = '0';
			ft_printf("\033[1;37mScore : %d\n\033[0m", mlx->score);
		}
		if ((mlx->data->map[y][x + 1] == 'E' && mlx->nb_col == mlx->data->pos->obj) || mlx->data->map[y][x + 1] == 'M' || mlx->data->map[y][x + 1] == 'B')
			mlx_loop_end(mlx->mlx);
		mlx->data->pos->player_col++;
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
		ft_map(mlx);
	}
}

void	ft_left(t_mlx *mlx)
{
	int	x;
	int	y;
	int	obj;

	x = mlx->data->pos->player_col;
	y = mlx->data->pos->player_row;
	obj = mlx->data->pos->obj;
	if (mlx->data->map[y][x - 1] != '1' && (mlx->data->map[y][x - 1] != 'E' || mlx->nb_col == obj))
	{
		if (mlx->data->map[y][x - 1] == 'C')
		{
			mlx->nb_col++;
			mlx->score += mlx->data->pos->ref_col_score;
			mlx->data->map[y][x - 1] = '0';
			ft_printf("\033[1;37mScore : %d\n\033[0m", mlx->score);
		}
		if ((mlx->data->map[y][x - 1] == 'E' && mlx->nb_col == mlx->data->pos->obj) || mlx->data->map[y][x - 1] == 'M' || mlx->data->map[y][x - 1] == 'B')
			mlx_loop_end(mlx->mlx);
		mlx->data->pos->player_col--;
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
		ft_map(mlx);
	}
}
