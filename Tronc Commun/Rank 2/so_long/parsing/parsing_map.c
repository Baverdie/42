/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:19:02 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/19 20:05:32 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	parse_map(t_data *data)
{
	int		rows;
	char	*line;

	rows = 0;
	data->fd = open(data->file_name, O_RDONLY);
	if (data->fd <= 0)
		return (0);
	data->map = ft_calloc(data->nb_rows + 1, sizeof(char *));
	if (!data->map)
		return (0);
	line = get_next_line(data->fd);
	while (line)
	{
		if (ft_strlen(line) > 1 && rows <= data->nb_rows)
		{
			data->map[rows] = ft_strdup(line);
			rows++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	free(line);
	return (1);
}

int	check_file(t_data *data, char *file)
{
	if (data->nb_cols == 0 && ft_strlen(file) > 1)
		data->nb_cols = ft_strlen(file);
	if (data->nb_cols != 0 && ft_strlen(file) > 1
		&& data->nb_cols != ft_strlen(file))
	{
		free(file);
		return (0);
	}
	return (1);
}

int	read_map(t_data *data)
{
	char	*file;

	data->fd = open(data->file_name, O_RDONLY);
	if (data->fd <= 0)
		return (0);
	file = get_next_line(data->fd);
	data->nb_rows = 0;
	data->nb_cols = 0;
	while (file)
	{
		if (check_file(data, file) == 0)
			return (0);
		if (data->nb_cols > 0 && ft_strlen(file) <= 1)
			break ;
		if (ft_strlen(file) > 1)
			data->nb_rows++;
		free(file);
		file = get_next_line(data->fd);
	}
	close(data->fd);
	free(file);
	return (1);
}

int	pos_data(t_data *data, t_game_positions *pos)
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

int	init_map(t_data *data)
{
	data->pos = ft_calloc(1, sizeof(t_game_positions));
	if (!data->pos)
		return (1);
	data->pos->player_col = 0;
	data->pos->player_row = 0;
	if (read_map(data) == 0)
		return (5);
	if (parse_map(data) == 0)
		return (1);
	if (pos_data(data, data->pos) == 0)
		return (4);
	if (check_errors(data) == 0)
		return (3);
	data->flood = ft_calloc(data->nb_rows + 1, sizeof(char *));
	if (!data->flood)
		return (1);
	data->flood = copy_map(data);
	flood(data->pos->player_row, data->pos->player_col, data, 0);
	if (check_path(data) == 0)
		return (2);
	return (0);
}
