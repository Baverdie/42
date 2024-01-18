/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:09:23 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/18 18:21:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pos_mob(t_data *data)
{
	int	i;
	int	j;

	data->mobs = ft_calloc(sizeof(t_mob *), count_mob(data));
	if (!data->mobs)
		return (ft_print_errors(ERROR_LABDA));
	data->pos->nb_mobs = count_mob(data);
	i = 0;
	data->counter_mob = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'M')
			{
				init_mob(data, data->counter_mob, i, j);
				data->counter_mob++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_rand_move(t_data *data, t_mob *mob, int rd)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i <= 4)
	{
		if (rd == 0 || rd == 2)
		{
			result = lateral(data, mob, rd);
			if (result != 1)
				return (result);
			rd++;
			i++;
		}
		if (rd == 1 || rd == 3)
		{
			result = vertical(data, mob, rd);
			if (result != 2)
				return (result);
			rd++;
			i++;
		}
	}
	return (-42);
}

int	define_new_mob_pos(t_data *data, t_mob *mob, int rand)
{
	data->map[mob->pos_y][mob->pos_x] = '0';
	if (rand == 0)
		mob->pos_x--;
	if (rand == 0)
		mob->dir = 0;
	if (rand == 1)
		mob->pos_y--;
	if (rand == 1)
		mob->dir = 1;
	if (rand == 2)
		mob->pos_x++;
	if (rand == 2)
		mob->dir = 2;
	if (rand == 3)
		mob->pos_y++;
	if (rand == 3)
		mob->dir = 3;
	data->map[mob->pos_y][mob->pos_x] = 'M';
	if (mob->pos_y == data->pos->player_row
		&& mob->pos_x == data->pos->player_col)
		return (-1);
	return (0);
}

int	move_mobs(t_data *data)
{
	int	i;
	int	rd;

	i = 0;
	while (i < data->pos->nb_mobs)
	{
		if (data->mobs[i]->is_alive == 0)
		{
			i++;
			continue ;
		}
		rd = -1;
		if (rd == -1)
			srand(time(NULL));
		if (rd == -1)
			rd = rand() % 4;
		rd = ft_check_rand_move(data, data->mobs[i], rd);
		if (rd != -42)
		{
			if (define_new_mob_pos(data, data->mobs[i], rd) < 0)
				return (1);
		}
		i++;
	}
	return (0);
}
