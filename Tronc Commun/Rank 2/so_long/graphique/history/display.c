/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:41:06 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/24 18:42:16 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_history(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(mlx->mlx, mlx->window);
	while (mlx->data->levels[mlx->data->nb_level]->map[i])
	{
		j = 0;
		while (mlx->data->levels[mlx->data->nb_level]->map[i][j])
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
