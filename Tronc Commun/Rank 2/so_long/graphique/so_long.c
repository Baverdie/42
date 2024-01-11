/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/11 14:04:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keycode, void *param)
{
	if (keycode == 0 || keycode == 41)
		mlx_loop_end(((t_mlx *)param)->mlx);
	return (0);
}

int	so_long(t_data *data)
{
	t_mlx	*mlx;
	int	i = 0;
	int	j = 0;
	int	width = 0;
	int	height = 0;

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->img = ft_calloc(1, sizeof(t_textures));
	if (!mlx || !mlx->img)
		return (EXIT_FAILURE);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "so_long");
	printf("cols = %d\nrows = %d\n", data->nb_cols, data->nb_rows);
	mlx->img->wall = mlx_png_file_to_image(mlx->mlx, "textures/wall.png", &mlx->img_size, &mlx->img_size);
	mlx->img->ground = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/ground.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player = mlx_png_file_to_image(mlx->mlx, "textures/Theme/Demon_Slayer/zenitsu.png", &mlx->img_size, &mlx->img_size);
	while (data->map[i])
	{
		j = 0;
		printf("line = %s", data->map[i]);
		while (data->map[i][j])
		{
			height = 0;
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->wall, j * 64, i * 64);
				// mlx_destroy_image(mlx->mlx, mlx->img);
			}
			else if (data->map[i][j] == '0')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->ground, j * 64, i * 64);
			}
			else if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player, j * 64, i * 64);
			}
			else if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
			{
				while (height <= 64)
				{
					width = 0;
					while (width < 64)
					{
						mlx_pixel_put(mlx->mlx, mlx->window, j * 64 + height, i * 64 + width, 0xffffffff);
						width++;
					}
					height++;
				}
			}
			j++;
		}
		i++;
	}
	print_map_full(data->map);
	mlx_on_event(mlx->mlx, mlx->window, MLX_KEYDOWN, ft_close, mlx);
	mlx_on_event(mlx->mlx, mlx->window, MLX_WINDOW_EVENT, ft_close, mlx);
	mlx_loop(mlx->mlx);
	mlx_destroy_image(mlx->mlx, mlx->img->wall);
	mlx_destroy_image(mlx->mlx, mlx->img->ground);
	mlx_destroy_image(mlx->mlx, mlx->img->player);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
