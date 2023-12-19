/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:26:50 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/19 18:20:57 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char	**map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_printf("%c", map[y][x]);
			x++;
		}
		y++;
	}
	ft_printf("/n/n");
}

void	print_map_x(int posx, int posy, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (x == posx && posy == y)
				ft_printf("\033[0;31mX\033[0m");
			else
				ft_printf("%c", map[y][x]);
			x++;
		}
		y++;
	}
	ft_printf("\n\n");
}

char	**copy_map(t_data *data)
{
	int	i;

	i = 0;
	data->flood = ft_calloc(data->nb_rows + 1, sizeof(char *));
	if (!data->flood)
		return (0);
	while (i < data->nb_rows)
	{
		data->flood[i] = ft_strdup(data->map[i]);
		i++;
	}
	return (data->flood);
}
