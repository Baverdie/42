/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:26:50 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/04 17:25:50 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_path_map(t_data *data, int err, int x, int y)
{
	if ((data->map[y][x] == 'P' && err == 5) \
	|| (data->map[y][x] == 'C' && err == 6) \
	|| (data->map[y][x] == 'E' && err == 7))
		ft_printf("\033[0;31m%c\033[0m", data->map[y][x]);
	else if (data->map[y][x] == 'P' || data->map[y][x] == 'C' \
	|| data->map[y][x] == 'E')
		ft_printf("\033[0;32m%c\033[0m", data->map[y][x]);
	else if (data->map[y][x] == '1')
		ft_printf("\033[0;37m%c\033[0m", 35);
	else if (data->map[y][x] == data->flood[y][x] && data->map[y][x] != '\n')
		ft_printf("\033[1;31m%c\033[0m", 'x');
	else if (data->flood[y][x] == '7')
		ft_printf("\033[0;36m%c\033[0m", '.');
}

void	print_map(t_data *data, int err)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] && data->map[y][0] != '\n')
	{
		x = 0;
		while (data->map[y][x] != '\n')
		{
			if (!data->flood[y])
			{
				ft_printf("\033[0;31mEmpty line\033[0m");
				break;
			}
			if (x == data->errorx && data->errory == y)
				ft_printf("\033[0;31m%c\033[0m", data->map[y][x]);
			else
				print_path_map(data, err, x, y);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	copy_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_rows)
	{
		data->flood[i] = ft_strdup(data->map[i]);
		i++;
	}
}
