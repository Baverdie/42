/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:26:50 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/15 14:49:27 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char **map)
{
	int	i = 0;

	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	
}
void	print_no_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' || data->map[i][j] == 'C' \
				|| data->map[i][j] == 'E')
				ft_printf("\033[0;32m%c\033[0m", data->map[i][j]);
			else if (data->map[i][j] == data->flood[i][j] && data->map[i][j] != '\n' && data->map[i][j] != '1')
				ft_printf("\033[1;31m%c\033[0m", 'x');
			else if (data->flood[i][j] == '7')
				ft_printf("\033[0;36m%c\033[0m", '.');
			else if (data->map[i][j] == '1')
				ft_printf("\033[0;37m%c\033[0m", 35);
			else
				ft_printf("\033[0;37m%c\033[0m", data->map[i][j]);
			j++;
		}
		i++;
	}
}

void	print_path_map(t_data *data, int x, int y)
{
	if ((x == 0 || x == data->nb_cols - 1 || y == 0 || y == data->nb_rows - 1) \
		&& data->map[y][x] != '1')
		ft_printf("\033[1;31m%c\033[0m", 'x');
	else if (data->map[y][x] == 'P' || data->map[y][x] == 'C' \
		|| data->map[y][x] == 'E')
		ft_printf("\033[0;32m%c\033[0m", data->map[y][x]);
	else if (data->map[y][x] == '1')
		ft_printf("\033[0;37m%c\033[0m", 35);
	else if (data->map[y][x] == '0')
		ft_printf("\033[0;36m%c\033[0m", '.');
}

void	print_map_errors(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			if (x == data->errorx && y == data->errory
				&& data->map[y][x] > 32 && data->map[y][x] < 127)
				ft_printf("\033[0;31m%c\033[0m", data->map[y][x]);
			else if (x == data->errorx && y == data->errory)
				ft_printf("\033[0;31mX\033[0m");
			else
				print_path_map(data, x, y);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	copy_map(char **dest, char **src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
}
