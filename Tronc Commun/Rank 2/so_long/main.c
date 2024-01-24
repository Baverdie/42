/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:41:31 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/24 18:48:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_extension(char *file, char *ext)
{
	char	*file_extension;
	char	*extension;

	extension = ext;
	file_extension = ft_strrchr(file, '.');
	if (file[ft_strlen(file) - 1] == '/')
		return (ft_print_errors(INVALID_FILE));
	else if (!file_extension || !ft_strcmp(file_extension, ""))
		return (ft_print_errors(INVALID_EXTENSION));
	else if (ft_strcmp(file_extension, extension) != 0)
		return (ft_print_errors(INVALID_EXTENSION));
	return (1);
}

int	history_mode(int level)
{
	t_data	*data;
	char	nb_level;
	t_mlx	*mlx;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_print_errors(ERROR_LABDA));
	data->nb_level = 5;
	data->levels = ft_calloc(sizeof(t_levels *), data->nb_level);
	while (level < 6)
	{
		init_levels(data, level);
		level++;
	}
	so_long_history(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 2)
		return (ft_print_errors(MORE_FILE));
	else if (argc < 2)
		return (ft_print_errors(NO_FILE));
	if (ft_strcmp(argv[1], "history") == 0)
	{
		history_mode(1);
		return (0);
	}
	if (file_extension(argv[1], ".ber") == 0)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_print_errors(ERROR_LABDA));
	data->file_name = argv[1];
	data->history = 0;
	if (init(data) == 0)
	{
		free_data(data);
		return (0);
	}
	so_long(data);
	return (0);
}
