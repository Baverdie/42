/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/08 12:05:00 by basverdi         ###   ########.fr       */
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
	if (!mlx)
		return (EXIT_FAILURE);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "so_long");
	printf("cols = %d\nrows = %d\n", data->nb_cols, data->nb_rows);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			height = 0;
			if (data->map[i][j] == '1')
			{
				// if (i == 0)
				// {
				// 	if (data->map[i + 1][j] == '1' && data->map[][])
				// }
				// printf("map[%d][%d] = %c\ndessus = %c\ndroite = %c\nbas = %c\ngauche = %c\n\n", i, j, data->map[i][j], data->map[i - 1][j], data->map[i][j + 1], data->map[i - 1][j], data->map[i][j - 1]);
				if (((j != data->nb_cols - 1 && data->map[i][j + 1] == '1') && (i != data->nb_rows - 1 && data->map[i + 1][j] == '1') && (j != 0 && data->map[i][j - 1] == '1') && (i != 0 && data->map[i - 1][j] == '1'))
					|| (i == 0 && j != 0 && data->map[i + 1][j] == '1' && data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1')
					|| (i == data->nb_rows - 1 && j != 0 && data->map[i - 1][j] == '1' && data->map[i][j - 1] == '1' && data->map[i][j + 1] == '1')
					|| (i > 0 && i < data->nb_rows - 1 && j == 0 && data->map[i - 1][j] == '1' && data->map[i][j + 1] == '1' && data->map[i + 1][j] == '1')
					|| (i > 0 && i < data->nb_rows - 1 && j == data->nb_cols - 2 && data->map[i - 1][j] == '1' && data->map[i][j - 1] == '1' && data->map[i + 1][j] == '1')
					|| ((i == 0 && j == 0 ) || (i == 0 && j == data->nb_cols - 2) || (i == data->nb_rows - 1 && j == 0) || (i == data->nb_rows - 1 && j == data->nb_cols - 2)))
					mlx->img = mlx_png_file_to_image(mlx->mlx, "textures/wall-full.png", &mlx->img_size, &mlx->img_size);
				else
					mlx->img = mlx_png_file_to_image(mlx->mlx, "textures/wall.png", &mlx->img_size, &mlx->img_size);
				mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, j * 64, i * 64);
				// mlx_destroy_image(mlx->mlx, mlx->img);
			}
			else if (data->map[i][j] == '0')
			{
				while (height <= 64)
				{
					width = 0;
					while (width <= 64)
					{
						mlx_pixel_put(mlx->mlx, mlx->window, j * 64 + height, i * 64 + width, 0xFF0000FF);
						width++;
					}
					height++;
				}
			}
			else if (data->map[i][j] == 'P' || data->map[i][j] == 'C' || data->map[i][j] == 'E')
			{
				while (height <= 64)
				{
					width = 0;
					while (width <= 64)
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
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
