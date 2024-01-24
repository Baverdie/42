/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:26:03 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/24 18:46:20 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	parse_map_history(t_levels *level, int id)
{
	char	*line;
	int		rows;

	rows = 0;
	level[id]->fd = open(level[id]->file_name, O_RDONLY);
	level[id]->map = ft_calloc(level[id]->nb_rows + 1, sizeof(char *));
	if (!level[id]->map || level[id]->fd <= 0)
		return (0);
	line = get_next_line(level[id]->fd);
	while (line && rows <= level[id]->nb_rows)
	{
		if (ft_strlen(line) > 1 && rows <= level[id]->nb_rows)
			level[id]->map[rows++] = ft_strdup(line);
		else if (ft_strlen(line) < 1 && rows > 0)
		{
			close(level[id]->fd);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(level[id]->fd);
	}
	close(level[id]->fd);
	free(line);
	return (1);
}

int	read_map_history(t_levels *level, int id)
{
	char	*file;

	level[id]->fd = open(level[id]->file_name, O_RDONLY);
	if (level[id]->fd <= 0)
		return (ft_print_errors(INVALID_FILE));
	file = get_next_line(level[id]->fd);
	level[id]->nb_rows = 0;
	level[id]->nb_cols = ft_strlen(file) - 1;
	while (file)
	{
		if (ft_strlen(file) < 3)
		{
			get_next_line(-42);
			return (0);
		}
		else if (ft_strlen(file) > 1)
			level[id]->nb_rows++;
		free(file);
		file = get_next_line(level[id]->fd);
	}
	close(level[id]->fd);
	free(file);
	return (1);
}

init_levels(t_data *data, int nb_level)
{
	data->levels[nb_level] = ft_calloc(sizeof(t_level), 1);
	if (!data->levels[nb_level])
		return (1);
	data->maps[nb_level]->id = nb_level;
	data->maps[nb_level]->file_name = ft_add_path("maps/history/level", \
		data->maps[nb_level]->id);
	read_map_history(data->levels[nb_level], level);
	parse_map_history(data->levels[nb_level], level);
}

char	*ft_strscpy(char *dest, char *src, int start)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[start] = src[i];
		i++;
		start++;
	}
	dest[start] = '\0';
	return (dest);
}

char	*ft_add_path(char *history, char level)
{
	char	*path;

	path = ft_calloc(ft_strlen(history) + ft_strlen(".ber") + 3, sizeof(char));
	path = ft_strscpy(path, history, 0);
	path[ft_strlen(history)] = level;
	path = ft_strscpy(path, ".ber", ft_strlen(history) + 1);
	path[ft_strlen(history) + ft_strlen(".ber") + 2] = '\0';
	return (path);
}
