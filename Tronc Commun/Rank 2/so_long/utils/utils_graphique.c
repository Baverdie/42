/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphique.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:25:24 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/18 18:26:25 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_free_img(t_mlx *mlx)
{
	if (mlx->img->player_left)
		mlx_destroy_image(mlx->mlx, mlx->img->player_left);
	if (mlx->img->player_right)
		mlx_destroy_image(mlx->mlx, mlx->img->player_right);
	if (mlx->img->player_top)
		mlx_destroy_image(mlx->mlx, mlx->img->player_top);
	if (mlx->img->mob_left)
		mlx_destroy_image(mlx->mlx, mlx->img->mob_left);
	if (mlx->img->mob_right)
		mlx_destroy_image(mlx->mlx, mlx->img->mob_right);
	if (mlx->img->mob_top)
		mlx_destroy_image(mlx->mlx, mlx->img->mob_top);
	if (mlx->img->wall)
		mlx_destroy_image(mlx->mlx, mlx->img->wall);
	if (mlx->img->ground)
		mlx_destroy_image(mlx->mlx, mlx->img->ground);
	if (mlx->img->exit)
		mlx_destroy_image(mlx->mlx, mlx->img->exit);
	if (mlx->img->col)
		mlx_destroy_image(mlx->mlx, mlx->img->col);
	if (mlx->img->tombstone)
		mlx_destroy_image(mlx->mlx, mlx->img->tombstone);
}

void ft_destroy(t_mlx *mlx)
{
	ft_free_img(mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->img);
	free_data(mlx->data);
	free(mlx);
}
