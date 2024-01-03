/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/03 18:40:59 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_mlx *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
	printf("ok\n");
	return (0);
}

int	so_long(t_data *data)
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
	if (!mlx->mlx)
		return (EXIT_FAILURE);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "so_long");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../textures/wall.xpm", &mlx->img_size, &mlx->img_size);
	
	printf("width = %d\nheight = %d\n", WIDTH, HEIGHT);
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
	mlx_hook(mlx->window, 17, 0, ft_close, mlx);
	printf("ok2\n");
	mlx_loop(mlx->mlx);
	return (EXIT_SUCCESS);
}