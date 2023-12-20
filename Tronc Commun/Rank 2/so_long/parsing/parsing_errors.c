/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:45:50 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/20 17:30:27 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	errors_type(t_data *data, int i, int j)
{
	if (data->map[i][j] == '0' || data->map[i][j] == 'P'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'C')
	{
		if (j == 0)
			return (0);
		if (i == 0)
			return (0);
		if (j == data->nb_cols - 2)
			return (0);
		if (i == data->nb_rows - 1)
			return (0);
		if (i > 0 && j < data->nb_cols && data->map[i - 1][j] == ' ')
			return (0);
		if (!data->map[i + 1])
			return (0);
		if (j < data->nb_cols && data->map[i][j + 1] == ' ')
			return (0);
		if (j > 0 && data->map[i][j - 1] == ' ')
			return (0);
	}
	return (1);
}

void	flood(int x, int y, t_data *data, int dir)
{
	if (x < data->nb_rows && y < data->nb_cols - 1 \
		&& (data->map[x][y] == '1' || data->flood[x][y] == '7'))
		return ;
	if (x < data->nb_rows && y < data->nb_cols - 1 && data->flood[x][y] != '7')
	{
		data->flood[x][y] = '7';
		if (dir == 0)
		{
			flood(x + 1, y, data, 1);
			flood(x, y + 1, data, 2);
		}
		if (x <= data->nb_rows - 1 && dir != -1 && data->flood[x + 1][y] != '7' \
			&& x + 1 != data->nb_rows - 1)
			flood(x + 1, y, data, 1);
		if (x > 0 && dir != 1 && data->flood[x - 1][y] != '7' && x - 1 != 0)
			flood(x - 1, y, data, -1);
		if (dir != -2 && y < data->nb_cols - 2 && data->flood[x][y + 1] != '7' \
			&& y + 1 != data->nb_cols - 1)
			flood(x, y + 1, data, 2);
		if (dir != 2 && y > 0 && data->flood[x][y - 1] != '7' && y - 1 != 0)
			flood(x, y - 1, data, -2);
	}
}

int	check_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->flood[i])
	{
		j = 0;
		while (data->flood[i][j])
		{
			if (data->flood[i][j] == 'P')
				return (1);
			if (data->flood[i][j] == 'C')
				return (2);
			if (data->flood[i][j] == 'E')
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (((i == 0 && data->map[i][j] != '1') \
			|| (i == data->nb_rows - 1 && data->map[i][j] != '1')) \
		|| ((i == 0 && data->map[i][data->nb_cols - 2] != '1') \
		|| (i == data->nb_rows - 1 && data->map[i][data->nb_cols - 2] != '1')))
			return (0);
		while (data->map[i][j])
		{
			if (errors_type(data, i, j) == 0)
			{
				data->errorx = j;
				data->errory = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
