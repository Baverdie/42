/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:34:46 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/13 16:14:44 by basverdi         ###   ########.fr       */
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

void	init_data(t_data *data)
{
	data->pos->player_col = 0;
	data->pos->player_row = 0;
	data->pos->exit_col = 0;
	data->pos->exit_row = 0;
	data->errorx = -1;
	data->errory = -1;
	data->pos->obj = 0;
	data->nb_0 = 0;
	data->pos->ref_mob_score = 0;
	data->pos->ref_col_score = 0;
	data->nb_rows = 0;
}

int	init(t_data *data)
{
	int	result;

	data->pos = ft_calloc(1, sizeof(t_game_object));
	if (!data->pos)
		return (ft_print_errors(ERROR_LABDA));
	init_data(data);
	result = read_map(data);
	if (result == 0)
		return (ft_print_errors(INVALID_MAP));
	else if (result == 2)
		return (ft_print_errors(EMPTY_FILE));
	if (parse_map(data) == 0)
		return (ft_print_errors(ERROR_LABDA));
	if (pos_data(data) == 0 || errors_map(data) == 0)
		return (0);
	return (1);
}
