/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:44:41 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/24 14:43:50 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_mob(t_mlx *mlx, int i, int j)
{
	int	count;

	count = 0;
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
	mlx->img->ground, j * 64, i * 64);
	if (!mlx->data->mobs[count]->dir || (mlx->data->mobs[count]->dir == 0
			|| mlx->data->mobs[count]->dir == 3))
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->mob_left, \
		j * 64, i * 64);
	else if (mlx->data->mobs[count]->dir == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->mob_right, \
	j * 64, i * 64);
	else if (mlx->data->mobs[count]->dir == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->mob_right, \
	j * 64, i * 64);
	count++;
}

void	display_exit(t_mlx *mlx, int i, int j)
{
	if (mlx->nb_col == mlx->data->pos->obj)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->exit);
		mlx->img->exit = mlx_png_file_to_image(mlx->mlx, \
		"textures/temple_open.png", &mlx->img_size, &mlx->img_size);
	}
	else if (mlx->nb_col > 0)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->exit);
		mlx->img->exit = mlx_png_file_to_image(mlx->mlx, \
		"textures/temple_half-open.png", &mlx->img_size, &mlx->img_size);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->exit, \
	j * 64, i * 64);
}

void	display_player(t_mlx *mlx, int i, int j)
{
	if (mlx->data->map[i][j] == 'E')
		display_exit(mlx, i, j);
	if (mlx->dir_player == 0 || mlx->dir_player == 3)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_left, \
	j * 64, i * 64);
	else if (mlx->dir_player == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_right,
			j * 64, i * 64);
	else if (mlx->dir_player == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_right,
			j * 64, i * 64);
	if (mlx->data->map[i][j] != 'E' && mlx->data->map[i][j] != 'T'
		&& mlx->data->map[i][j] != '2')
		mlx->data->map[i][j] = '0';
}

void	display_element(t_mlx *mlx, int i, int j)
{
	if (mlx->data->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->wall, \
	j * 64, i * 64);
	else if ((i == mlx->data->pos->player_row \
		&& j == mlx->data->pos->player_col) || mlx->data->map[i][j] == 'P')
		display_player(mlx, i, j);
	else if (mlx->data->map[i][j] == 'E')
		display_exit(mlx, i, j);
	else if (mlx->data->map[i][j] == 'T')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->tombstone, \
	j * 64, i * 64);
	else if (mlx->data->map[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, \
	j * 64, i * 64);
	else if (mlx->data->map[i][j] == '2')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, \
	j * 64, i * 64);
	else if (mlx->data->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->col, \
	j * 64, i * 64);
	else if (mlx->data->map[i][j] == 'M')
		display_mob(mlx, i, j);
}
