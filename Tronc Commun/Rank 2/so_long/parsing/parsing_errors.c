/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:45:50 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/18 15:17:03 by basverdi         ###   ########.fr       */
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
	printf("ici");
	if (data->map[x][y] == '0' || data->map[x][y] == 'C')
	{
		// putpixel(x, y, new_col, data);
		flood(x + 1, y, new_col, data);
		flood(x - 1, y, new_col, data);
		flood(x, y + 1, new_col, data);
		flood(x, y - 1, new_col, data);
	}
}

int	check_errors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	printf("ici2");
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
			printf("ici");
			if (errors(data, i, j) == 0)
				return (0);
			printf("ici1");
			flood(j, i, '7', data);
			j++;
		}
		i++;
	}
	return (1);
}
