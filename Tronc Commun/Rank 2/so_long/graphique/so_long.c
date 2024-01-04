/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/04 17:02:58 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keycode, void *param)
{
	if (keycode == 0 || keycode == 41)
		mlx_loop_end(((t_mlx *)param)->mlx);
	return (0);
}

int	so_long()
{
	t_mlx	*mlx;
	// int	i = 0;
	// int	j = 0;
	// int	width = 0;
	// int	height = 0;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (EXIT_FAILURE);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, 1920, 1080, "so_long");
	// mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	// mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../textures/wall.xpm", &mlx->img_size, &mlx->img_size);
	// while (data->map[i])
	// {
	// 	j = 0;
	// 	while (data->map[i][j])
	// 	{
	// 		height = 0;
	// 		if (data->map[i][j] == '1')
	// 		{
	// 			while (height <= 64)
	// 			{
	// 				width = 0;
	// 				while (width <= 64)
	// 				{
	// 					my_mlx_put_pixel(img, j * 64 + height, i * 64 + width, 0xFF0000FF);
	// 					width++;
	// 				}
	// 				height++;
	// 			}
	// 		}
	// 		else if (data->map[i][j] == '0')
	// 		{
	// 			while (height <= 64)
	// 			{
	// 				width = 0;
	// 				while (width <= 64)
	// 				{
	// 					my_mlx_put_pixel(img, j * 64 + height, i * 64 + width, 0x0000FF);
	// 					width++;
	// 				}
	// 				height++;
	// 			}
	// 		}
	// 		else if (data->map[i][j] == 'P' || data->map[i][j] == 'C' || data->map[i][j] == 'E')
	// 		{
	// 			while (height <= 64)
	// 			{
	// 				width = 0;
	// 				while (width <= 64)
	// 				{
	// 					my_mlx_put_pixel(img, j * 64 + height, i * 64 + width, 0xFFFF);
	// 					width++;
	// 				}
	// 				height++;
	// 			}
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_on_event(mlx->mlx, mlx->window, MLX_KEYDOWN, ft_close, mlx);
	mlx_on_event(mlx->mlx, mlx->window, MLX_WINDOW_EVENT, ft_close, mlx);
	mlx_loop(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
