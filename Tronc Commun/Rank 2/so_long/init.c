/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:34:46 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/14 01:11:41 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errors_map(t_data *data)
{
	data->flood = ft_calloc(data->nb_rows + 1, sizeof(char *));
	if (!data->flood)
		return (ft_print_errors(ERROR_LABDA));
	copy_map(data->flood, data->map, data->nb_rows);
	flood(data->pos->player_row, data->pos->player_col, data, 0);
	if (check_errors(data) == 0 && check_path(data) != 0)
	{
		print_map_errors(data);
		return (ft_print_errors(INVALID_NO_PATH));
	}
	if (check_errors(data) == 0)
	{
		print_map_errors(data);
		return (ft_print_errors(INVALID_MAP));
	}
	if (check_path(data) != 0)
	{
		print_map_errors(data);
		return (ft_print_errors(NO_PATH));
	}
	return (1);
}

int	init(t_data *data)
{
	data->pos = ft_calloc(1, sizeof(t_game_object));
	if (!data->pos)
		return (ft_print_errors(ERROR_LABDA));
	data->pos->player_col = 0;
	data->pos->player_row = 0;
	data->pos->exit_col = 0;
	data->pos->exit_row = 0;
	data->errorx = -1;
	data->errory = -1;
	data->pos->obj = 0;
	if (read_map(data) == 0)
		return (ft_print_errors(INVALID_MAP));
	if (parse_map(data) == 0)
		return (ft_print_errors(ERROR_LABDA));
	if (pos_data(data) == 0)
		return (0);
	if (errors_map(data) == 0)
		return (0);
	return (1);
}
