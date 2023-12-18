/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:45:50 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/18 18:46:00 by basverdi         ###   ########.fr       */
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

void	flood(int x, int y, int new_col, t_data *data)
{
	printf("PARAMS :\n	x = %d y = %d\n	new_col = %c data->map[%d][%d] = %c\n", x, y, new_col, x, y, data->map[x][y]);

	data->flood[x] = ft_calloc(data->nb_cols + 1, sizeof(char));
	if (x < data->nb_rows - 1 && y < data->nb_cols - 1 && (data->map[x][y] == '0' || data->map[x][y] == 'C'))
	{
		data->flood[x][y] = new_col;
		if (x == 0 && y == 0)
		{
			flood(x + 1, y, new_col, data);
			flood(x, y + 1, new_col, data);
		}
		if (x > 0 && x <= data->nb_rows - 1)
			flood(x + 1, y, new_col, data);
		if (y > 0 && y < data->nb_cols - 2)
			flood(x, y + 1, new_col, data);
		// if (x > 0 && x < data->nb_rows - 1)
		// 	flood(x - 1, y, new_col, data);
		// if (y > 0 && y < data->nb_cols - 1)
		// 	flood(x, y - 1, new_col, data);
	}
	else if (x < data->nb_rows - 1 && y < data->nb_cols - 1)
	{
		data->flood[x][y] = '1';
		if (x == 0 && y == 0)
		{
			flood(x + 1, y, new_col, data);
			flood(x, y + 1, new_col, data);
		}
		if (x >= 0 && x <= data->nb_rows - 1)
			flood(x + 1, y, new_col, data);
		if (y >= 0 && y < data->nb_cols - 2)
			flood(x, y + 1, new_col, data);
		// if (x > 0 && x < data->nb_rows - 1)
		// 	flood(x - 1, y, new_col, data);
		// if (y > 0 && y < data->nb_cols - 1)
		// 	flood(x, y - 1, new_col, data);
	}
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
			j++;
		}
		i++;
	}
	return (1);
}
