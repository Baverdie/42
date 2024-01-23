/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:07:24 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/23 13:09:39 by basverdi         ###   ########.fr       */
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
