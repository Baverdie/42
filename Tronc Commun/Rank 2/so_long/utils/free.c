/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:37:01 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/18 12:58:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_mobs(t_data *data)
{
	while(data->counter_mob > 0)
	{
		data->counter_mob--;
		free(data->mobs[data->counter_mob]);
	}
	free(data->mobs);
}

void	free_data(t_data *data)
{
	if (data->mobs)
		ft_free_mobs(data);
	if (data->flood)
		ft_free_map(data->flood);
	if (data->map)
		ft_free_map(data->map);
	free(data->pos);
	free(data);
}

void ft_destroy(t_mlx *mlx)
{
	if (mlx->img->wall)
		mlx_destroy_image(mlx->mlx, mlx->img->wall);
	if (mlx->img->ground)
		mlx_destroy_image(mlx->mlx, mlx->img->ground);
	if (mlx->img->player_left)
		mlx_destroy_image(mlx->mlx, mlx->img->player_left);
	if (mlx->img->player_right)
		mlx_destroy_image(mlx->mlx, mlx->img->player_right);
	// if (mlx->img->player_top)
	// 	mlx_destroy_image(mlx->mlx, mlx->img->player_top);
	if (mlx->img->exit)
		mlx_destroy_image(mlx->mlx, mlx->img->exit);
	if (mlx->img->col)
		mlx_destroy_image(mlx->mlx, mlx->img->col);
	if (mlx->img->mob_left)
		mlx_destroy_image(mlx->mlx, mlx->img->mob_left);
	if (mlx->img->mob_right)
		mlx_destroy_image(mlx->mlx, mlx->img->mob_right);
	// if (mlx->img->mob_top)
	// 	mlx_destroy_image(mlx->mlx, mlx->img->mob_top);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->img);
	free_data(mlx->data);
	free(mlx);
}
