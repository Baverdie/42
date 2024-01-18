/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:16 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/18 13:15:25 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		"textures/ground2.png", &mlx->img_size, &mlx->img_size);
	mlx->img->ground = mlx_png_file_to_image(mlx->mlx, \
		"textures/ground.png", &mlx->img_size, &mlx->img_size);
	// mlx->img->player_top = mlx_png_file_to_image(mlx->mlx, '\'
		// "textures/zenitsu.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player_right = mlx_png_file_to_image(mlx->mlx, \
		"textures/zenitsu_right.png", &mlx->img_size, &mlx->img_size);
	mlx->img->player_left = mlx_png_file_to_image(mlx->mlx, \
		"textures/zenitsu_left.png", &mlx->img_size, &mlx->img_size);
	mlx->img->exit = mlx_png_file_to_image(mlx->mlx, \
		"textures/temple_close.png", &mlx->img_size, &mlx->img_size);
	mlx->img->col = mlx_png_file_to_image(mlx->mlx, \
		"textures/sabre_mid.png", &mlx->img_size, &mlx->img_size);
	// mlx->img->mob_top = mlx_png_file_to_image(mlx->mlx, '\'
		// "textures/muzan.png", &mlx->img_size, &mlx->img_size);
	mlx->img->mob_right = mlx_png_file_to_image(mlx->mlx, \
		"textures/muzan_right.png", &mlx->img_size, &mlx->img_size);
	mlx->img->mob_left = mlx_png_file_to_image(mlx->mlx, \
		"textures/muzan_left.png", &mlx->img_size, &mlx->img_size);
}

int	update(void *param)
{
	t_mlx	*mlx;
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx = (t_mlx *)param;
	if (mlx->nb_frames == 10000)	
	{
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
					display_mob(mlx, i, j);
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
	init_vars(mlx, data);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "so_long");
	set_img(mlx);
	if (!mlx->img->wall || !mlx->img->ground || !mlx->img->player_right || !mlx->img->player_left || !mlx->img->exit || !mlx->img->col)
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
	if (mlx->nb_col == mlx->data->pos->obj)
		ft_printf("\n\033[1;32mYou Win !\n\033[0m");
	else
		ft_printf("\n\033[1;31mGame over !\n\033[0m");
	ft_printf("\033[1;37mFinal Score : %d \033[0m\nTotal Mouvements : %d\n", mlx->score, mlx->nb_move);
	ft_destroy(mlx);
	return (0);
}
