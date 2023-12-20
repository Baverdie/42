/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:34:46 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/20 17:25:25 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_data *data)
{
	if (read_map(data) == 0)
		return (4);
	if (parse_map(data) == 0)
		return (1);
	if (pos_data(data) == 1)
		return (3);
	else if (pos_data(data) == 2)
		return (8);
	else if (pos_data(data) == 3)
		return (9);
	if (check_errors(data) == 0)
		return (2);
	data->flood = ft_calloc(data->nb_rows + 1, sizeof(char *));
	if (!data->flood)
		return (1);
	copy_map(data);
	flood(data->pos->player_row, data->pos->player_col, data, 0);
	if (check_path(data) == 1)
		return (5);
	if (check_path(data) == 2)
		return (6);
	if (check_path(data) == 3)
		return (7);
	return (0);
}

int	init(t_data *data)
{
	int	errors;

	data->pos = ft_calloc(1, sizeof(t_game_positions));
	if (!data->pos)
		return (1);
	data->pos->player_col = 0;
	data->pos->player_row = 0;
	data->pos->exit_col = 0;
	data->pos->exit_row = 0;
	data->pos->obj = 0;
	errors = init_map(data);
	return (errors);
}
