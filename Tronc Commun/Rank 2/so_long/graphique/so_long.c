/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/14 07:15:17 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keycode, void *param)
{
	if (keycode == 0 || keycode == 41)
	{
		ft_printf("\033[0;31mGive up !\033[0m\n");
		mlx_loop_end(((t_mlx *)param)->mlx);
	}
	return (0);
}

int	ft_key(int keycode, void *param)
{
	if (keycode == 41)
		ft_close(keycode, (t_mlx *)param);
	else if (keycode == 26 || keycode == 82)
		ft_forward((t_mlx *)param);
	else if (keycode == 4 || keycode == 80)
		ft_left((t_mlx *)param);
	else if (keycode == 22 || keycode == 81)
		ft_backward((t_mlx *)param);
	else if (keycode == 7 || keycode == 79)
		ft_right((t_mlx *)param);
	else if (keycode == 44)
		ft_dash((t_mlx *)param);
	return (0);
}

void ft_event(t_mlx *mlx)
{
	mlx_on_event(mlx->mlx, mlx->window, MLX_KEYDOWN, ft_key, mlx);
	mlx_on_event(mlx->mlx, mlx->window, MLX_WINDOW_EVENT, ft_close, mlx);
}

int	ft_map(t_mlx *mlx)
{
	int	i = 0;
	int	j = 0;
	
	mlx_clear_window(mlx->mlx, mlx->window);
	while (mlx->data->map[i])
	{
		j = 0;
		while (mlx->data->map[i][j])
		{
			if (mlx->data->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->wall, j * 64, i * 64);
			else if ((i == mlx->data->pos->player_row && j == mlx->data->pos->player_col) || mlx->data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player, j * 64, i * 64);
				if (mlx->data->map[i][j] != 'E')
					mlx->data->map[i][j] = '0';
			}
			else if (mlx->data->map[i][j] == 'E')
			{
				if (mlx->nb_col == mlx->data->pos->obj)
				{
					mlx_destroy_image(mlx->mlx, mlx->img->exit);
					mlx->img->exit = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/temple_open.png", &mlx->img_size, &mlx->img_size);
				}
				else if (mlx->nb_col > 0)
				{
					mlx_destroy_image(mlx->mlx, mlx->img->exit);
					mlx->img->exit = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/temple_half-open.png", &mlx->img_size, &mlx->img_size);
				}
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->exit, j * 64, i * 64);
			}
			else if (mlx->data->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, j * 64, i * 64);
			else if (mlx->data->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->col, j * 64, i * 64);
			else if (mlx->data->map[i][j] == 'M')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, j * 64, i * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->mob, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
	ft_str_display(mlx);
	ft_event(mlx);
	return (0);
}

void	set_img(t_mlx *mlx)
{
	mlx->img->wall = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/ground2.png", &mlx->img_size, &mlx->img_size);
	mlx->img->ground = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/ground.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/zenitsu.png", &mlx->img_size, &mlx->img_size);
	mlx->img->exit = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/temple_close.png", &mlx->img_size, &mlx->img_size);
	mlx->img->col = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/sabre_mid.png", &mlx->img_size, &mlx->img_size);
	mlx->img->mob = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/muzan.png", &mlx->img_size, &mlx->img_size);
}

int	update(void *param)
{
	t_mlx	*mlx = (t_mlx *)param;

	if (mlx->nb_frames == 10000)	
	{
		int	i = 0;
		int	j = 0;

		while (mlx->data->map[i])
		{
			j = 0;
			while (mlx->data->map[i][j])
			{
				if (mlx->data->map[i][j] == 'M')
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, j * 64, i * 64);
				j++;
			}
			i++;
		}
		if (move_mobs(mlx->data))
			mlx_loop_end(mlx->mlx);
		i = 0;
		j = 0;
		while (mlx->data->map[i])
		{
			j = 0;
			while (mlx->data->map[i][j])
			{
				if (mlx->data->map[i][j] == 'M')
				{
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, j * 64, i * 64);
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->mob, j * 64, i * 64);
				}
				j++;
			}
			i++;
		}
		mlx->nb_frames = 0;
	}
	mlx->nb_frames++;
	
	return (0);
}

int	so_long(t_data *data)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->img = ft_calloc(1, sizeof(t_textures));
	if (!mlx || !mlx->img)
		return (ft_print_errors(ERROR_LABDA));
	init_vars(mlx, data);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "so_long");
	set_img(mlx);
	if (!mlx->img->wall || !mlx->img->ground || !mlx->img->player || !mlx->img->exit || !mlx->img->col)
	{
		ft_print_errors(MISSING_TEXTURE);
		mlx_loop_end(mlx->mlx);
	}
	else
	{
		ft_map(mlx);
		mlx_loop_hook(mlx->mlx, update, mlx);
	}
	mlx_loop(mlx->mlx);
	ft_printf("\033[1;33mFinal Score : %d \033[0m\n", mlx->score);
	ft_destroy(mlx);
	return (0);
}
