/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:29 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/20 17:29:19 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pos_player(t_data *data, t_game_positions *pos)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				pos->player_row = i;
				pos->player_col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	count_obj(t_data *data, t_game_positions *pos)
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

int	pos_exit(t_data *data, t_game_positions *pos)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				pos->exit_row = i;
				pos->exit_col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	pos_data(t_data *data)
{
	count_obj(data, data->pos);
	if (pos_player(data, data->pos) == 0)
		return (1);
	else if (pos_exit(data, data->pos) == 0)
		return (2);
	else if (data->pos->obj == 0)
		return (3);
	return (0);
}
