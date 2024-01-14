/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:48:40 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/13 21:51:55 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_dash(t_mlx *mlx)
{
	char **map;
	int	x;
	int	y;
	int	obj;
	
	map == 
	if (mlx->dir == 0 && )
}

void	ft_dash(t_mlx *mlx)
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
			mlx->nb_col++;
		if (mlx->data->map[y][x - 1] == 'E' && mlx->nb_col == mlx->data->pos->obj)
			mlx_loop_end(mlx->mlx);
		mlx->data->pos->player_col--;
		mlx->nb_move += 1;
		ft_printf("Movements : %d\n", mlx->nb_move);
		ft_map(mlx);
	}
}