/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:57:34 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/16 19:58:35 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keycode, void *param)
{
	if (keycode == 0 || keycode == 41)
		mlx_loop_end(((t_mlx *)param)->mlx);
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
