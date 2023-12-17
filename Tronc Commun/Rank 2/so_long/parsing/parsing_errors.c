/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:45:50 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/17 13:50:43 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	errors(t_data *data, int i, int j)
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

int	flood(int x, int y, int new_col)
{
	if (data->map[x][y] == )
	{
		putpixel(x, y, new_col);
		flood(x + 1, y, new_col);
		flood(x - 1, y, new_col);
		flood(x, y + 1, new_col);
		flood(x, y - 1, new_col);
	}
	return (1);
}

int	check_errors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if ((i == 0 && data->map[i][j] != '1')
			|| (i == data->nb_rows - 1 && data->map[i][j] != '1'))
			return (0);
		if ((i == 0 && data->map[i][data->nb_cols - 2] != '1')
			|| (i == data->nb_rows - 1
			&& data->map[i][data->nb_cols - 2] != '1'))
			return (0);
		while (data->map[i][j])
		{
			if (errors(data, i, j) == 0)
				return (0);
			if (flood(i, j, data) == 0)
				return (0)
			j++;
		}
		i++;
	}
	return (1);
}
