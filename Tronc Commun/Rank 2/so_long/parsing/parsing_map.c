/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:19:02 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/18 15:17:27 by basverdi         ###   ########.fr       */
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

int	init_map(t_data *data)
{
	printf("ici4");
	if (read_map(data) == 0)
		return (0);
	if (parse_map(data) == 0)
		return (0);
	if (check_errors(data) == 0)
		return (0);
	return (1);
}
