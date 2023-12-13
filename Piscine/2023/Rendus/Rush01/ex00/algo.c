/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:39:50 by bedarenn          #+#    #+#             */
/*   Updated: 2023/07/23 19:47:28 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	check_all(int **tab, int **arg, int size, int coord)
{
	int	y;
	int	x;

	y = coord / size;
	x = coord % size;
	if (coord / size == size - 1)
		if (!check_arg_column_bot(tab, arg, x, size))
			return (0);
	if (coord % size == size - 1)
		if (!check_arg_line_right(tab, arg, y, size))
			return (0);
	return (check_arg_column_top(tab, arg, x, size)
		&& check_arg_line_left(tab, arg, y, size)
		&& check_occ(tab, size, y, x));
}

int	algo(int **tab, int **arg, int size, int coord)
{
	int	y;
	int	x;

	y = coord / size;
	x = coord % size;
	while (tab[y][x] < size)
	{
		tab[y][x]++;
		if (check_all(tab, arg, size, coord))
		{
			if (coord == size * size - 1)
				return (1);
			if (algo(tab, arg, size, coord + 1))
				return (1);
		}
	}
	tab[y][x] = 0;
	return (0);
}
