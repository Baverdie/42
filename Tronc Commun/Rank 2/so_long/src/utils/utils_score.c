/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:07:24 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/24 13:53:02 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	add_score_y(t_data *data, int i, int x, int y)
{
	int	scores;

	scores = 0;
	if (i <= 3 && data->map[y][x] == 'M')
		scores += data->pos->ref_mob_score;
	if (data->map[y][x] == 'C')
		scores += data->pos->ref_col_score;
	return (scores);
}

int	add_score_x(t_data *data, int i, int x, int y)
{
	int	scores;

	scores = 0;
	if (i <= 3 && data->map[y][x] == 'M')
		scores += data->pos->ref_mob_score;
	if (data->map[y][x] == 'C')
		scores += data->pos->ref_col_score;
	return (scores);
}

int	ft_print_score(t_mlx *mlx, int nb_kill)
{
	if (nb_kill == 1)
		ft_printf("\033[1;31mOne Kill !\033[0m\n");
	if (nb_kill == 2)
	{
		ft_printf("\033[1;31mDouble Kill +10 points !\033[0m\n");
		mlx->score += 10;
	}
	else if (nb_kill == 3)
	{
		ft_printf("\033[1;31mTriple Kill +50 points !\033[0m\n");
		mlx->score += 50;
	}
	ft_printf("\033[1;37mScore : %d\033[0m\n", mlx->score);
	return (0);
}
