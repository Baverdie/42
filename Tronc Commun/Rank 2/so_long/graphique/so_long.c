/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/15 13:04:11 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(mlx->mlx, mlx->window);
	while (mlx->data->map[i])
	{
		j = 0;
		while (mlx->data->map[i][j])
		{
			display_element(mlx, i, j);
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
	mlx->img->wall = mlx_png_file_to_image(mlx->mlx, \
		"textures/wall.png", &mlx->img_size, &mlx->img_size);
	mlx->img->ground = mlx_png_file_to_image(mlx->mlx, \
		"textures/floor.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player_top = mlx_png_file_to_image(mlx->mlx, \
		"textures/player_left.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player_right = mlx_png_file_to_image(mlx->mlx, \
		"textures/player_right.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player_left = mlx_png_file_to_image(mlx->mlx, \
		"textures/player_left.png", &mlx->img_size, &mlx->img_size);
	mlx->img->exit = mlx_png_file_to_image(mlx->mlx, \
		"textures/door_close.png", &mlx->img_size, &mlx->img_size);
	mlx->img->col = mlx_png_file_to_image(mlx->mlx, \
		"textures/collectible.png", &mlx->img_size, &mlx->img_size);
	mlx->img->mob_top = mlx_png_file_to_image(mlx->mlx, \
		"textures/mob_left.png", &mlx->img_size, &mlx->img_size);
	mlx->img->mob_right = mlx_png_file_to_image(mlx->mlx, \
		"textures/mob_right.png", &mlx->img_size, &mlx->img_size);
	mlx->img->mob_left = mlx_png_file_to_image(mlx->mlx, \
		"textures/mob_left.png", &mlx->img_size, &mlx->img_size);
	mlx->img->tombstone = mlx_png_file_to_image(mlx->mlx, \
		"textures/floor_tomb.png", &mlx->img_size, &mlx->img_size);
}

int	update(void *param)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (((t_mlx *)param)->nb_frames == 10000)
	{
		while (((t_mlx *)param)->data->map[i])
		{
			j = 0;
			while (((t_mlx *)param)->data->map[i][j])
			{
				if (((t_mlx *)param)->data->map[i][j] == 'M')
					mlx_put_image_to_window(((t_mlx *)param)->mlx, \
				((t_mlx *)param)->window, \
				((t_mlx *)param)->img->ground, j * 32, i * 32);
				j++;
			}
			i++;
		}
		print_map_mob((t_mlx *)param);
	}
	((t_mlx *)param)->nb_frames++;
	return (0);
}

int	so_long(t_data *data)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (ft_print_errors(ERROR_LABDA));
	init_vars(mlx, data);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, mlx->data->nb_cols * 32, \
		mlx->data->nb_rows * 32, "so_long");
	set_img(mlx);
	ft_map(mlx);
	mlx_loop_hook(mlx->mlx, update, mlx);
	mlx_loop(mlx->mlx);
	ft_print_end(mlx);
	ft_destroy(mlx);
	return (0);
}
