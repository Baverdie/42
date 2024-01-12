/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/12 18:53:47 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keycode, void *param)
{
	if (keycode == 0 || keycode == 41)
		mlx_loop_end(((t_mlx *)param)->mlx);
	return (0);
}

int	ft_map(t_mlx *mlx, t_data *data)
{
	int	i = 0;
	int	j = 0;
	
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->wall, j * 64, i * 64);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, j * 64, i * 64);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player, j * 64, i * 64);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->exit, j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->col, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_move()
{
	printf("ok\n");
	return (0);
}

void ft_event(t_mlx *mlx)
{
	mlx_on_event(mlx->mlx, mlx->window, MLX_KEYDOWN, ft_close, mlx);
	mlx_on_event(mlx->mlx, mlx->window, MLX_WINDOW_EVENT, ft_close, mlx);
}

int	so_long(t_data *data)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->img = ft_calloc(1, sizeof(t_textures));
	if (!mlx || !mlx->img)
		return (EXIT_FAILURE);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "so_long");
	mlx->img->wall = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/ground2.png", &mlx->img_size, &mlx->img_size);
	mlx->img->ground = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/ground.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/zenitsu.png", &mlx->img_size, &mlx->img_size);
	mlx->img->exit = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/temple_close.png", &mlx->img_size, &mlx->img_size);
	mlx->img->col = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/sabre_mid.png", &mlx->img_size, &mlx->img_size);
	if (!mlx->img->wall || !mlx->img->ground || !mlx->img->player || !mlx->img->exit || !mlx->img->col)
	{
		ft_print_errors(MISSING_TEXTURE);
		mlx_loop_end(mlx->mlx);
	}
	else
		ft_map(mlx, data);
	ft_event(mlx);
	mlx_loop(mlx->mlx);
	ft_destroy(mlx);
	return (0);
}
