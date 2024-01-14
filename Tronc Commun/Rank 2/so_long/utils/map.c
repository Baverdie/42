/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:26:50 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/13 16:32:00 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_path_map(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P' || data->map[y][x] == 'C' \
		|| data->map[y][x] == 'E')
		ft_printf("\033[0;32m%c\033[0m", data->map[y][x]);
	else if (data->map[y][x] == '1')
		ft_printf("\033[0;37m%c\033[0m", 35);
	else if (data->map[y][x] == data->flood[y][x] && data->map[y][x] != '\n')
		ft_printf("\033[1;31m%c\033[0m", 'x');
	else if (data->flood[y][x] == '7')
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
			if (x == data->errorx && y == data->errory && data->map[y][x] > 32 && data->map[y][x] < 127)
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
