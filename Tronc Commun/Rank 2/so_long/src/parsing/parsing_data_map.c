/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:29 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/14 00:43:39 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pos_player(t_data *data, t_game_object *pos)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' && pos->player_col != 0)
				return (ft_print_errors(MULTIPLE_PLAYER));
			else if (data->map[i][j] == 'P')
			{
				pos->player_row = i;
				pos->player_col = j;
			}
			j++;
		}
		i++;
	}
	if (pos->player_col != 0)
		return (1);
	return (ft_print_errors(MISSING_PLAYER));
}

void	count_obj(t_data *data, t_game_object *pos)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				pos->obj++;
			}
			j++;
		}
		i++;
	}
}

int	pos_exit(t_data *data, t_game_object *pos)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' && pos->exit_col != 0)
				return (ft_print_errors(MULTIPLE_EXIT));
			else if (data->map[i][j] == 'E')
			{
				pos->exit_row = i;
				pos->exit_col = j;
			}
			j++;
		}
		i++;
	}
	if (pos->exit_col != 0)
		return (1);
	return (ft_print_errors(MISSING_EXIT));
}

int	pos_data(t_data *data)
{
	count_obj(data, data->pos);
	if (pos_player(data, data->pos) == 0)
		return (0);
	else if (pos_exit(data, data->pos) == 0)
		return (0);
	else if (pos_mob(data) == 0)
		return (0);
	else if (data->pos->obj == 0)
		return (ft_print_errors(COL_ERROR));
	return (1);
}
