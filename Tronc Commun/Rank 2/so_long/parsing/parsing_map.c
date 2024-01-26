/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:19:02 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/26 08:45:50 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	parse_map(t_data *data)
{
	char	*line;
	int		rows;

	rows = 0;
	data->fd = open(data->file_name, O_RDONLY);
	data->map = ft_calloc(data->nb_rows + 1, sizeof(char *));
	if (!data->map || data->fd <= 0)
		return (0);
	line = get_next_line(data->fd);
	while (line && rows <= data->nb_rows)
	{
		if (ft_strlen(line) > 1 && rows <= data->nb_rows)
			data->map[rows++] = ft_strdup(line);
		else if (ft_strlen(line) < 1 && rows > 0)
		{
			close(data->fd);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	free(line);
	return (1);
}

int	read_map(t_data *data)
{
	char	*file;

	data->fd = open(data->file_name, O_RDONLY);
	if (data->fd <= 0)
		return (ft_print_errors(INVALID_FILE));
	file = get_next_line(data->fd);
	data->nb_rows = 0;
	data->nb_cols = ft_strlen(file);
	if (data->nb_cols == 0)
		return (2);
	while (file)
	{
		if (ft_strlen(file) < 3 || ft_strlen(file) != data->nb_cols)
		{
			get_next_line(-42);
			return (0);
		}
		else if (ft_strlen(file) > 1)
			data->nb_rows++;
		free(file);
		file = get_next_line(data->fd);
	}
	close(data->fd);
	free(file);
	return (1);
}
