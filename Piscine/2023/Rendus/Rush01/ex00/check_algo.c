/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:02:01 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/23 19:47:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	check_arg_column_top(int **tab, int **arg, int x, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < size && max < size && count <= arg[0][x])
	{
		if (tab[i][x] == 0)
			return (1);
		if (max < tab[i][x])
		{
			max = tab[i][x];
			count++;
		}
		i++;
	}	
	if (count == arg[0][x])
		return (1);
	return (0);
}

int	check_arg_column_bot(int **tab, int **arg, int x, int size)
{
	int	i;
	int	max;
	int	count;

	i = size - 1;
	max = 0;
	count = 0;
	while (i >= 0 && max < size && count <= arg[1][x])
	{
		if (tab[i][x] == 0)
			return (1);
		if (max < tab[i][x])
		{
			max = tab[i][x];
			count++;
		}
		i--;
	}
	if (count == arg[1][x])
		return (1);
	return (0);
}

int	check_arg_line_left(int **tab, int **arg, int y, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < size && max < size && count <= arg[2][y])
	{
		if (tab[y][i] == 0)
			return (1);
		if (max < tab[y][i])
		{
			max = tab[y][i];
			count++;
		}
		i--;
	}
	if (count == arg[2][y])
		return (1);
	return (0);
}

int	check_arg_line_right(int **tab, int **arg, int y, int size)
{
	int	i;
	int	max;
	int	count;

	i = size - 1;
	max = 0;
	count = 0;
	while (i >= 0 && max < size && count <= arg[3][y])
	{
		if (tab[y][i] == 0)
			return (1);
		if (max < tab[y][i])
		{
			max = tab[y][i];
			count++;
		}
		i--;
	}
	if (count == arg[3][y])
		return (1);
	return (0);
}

int	check_occ(int **tab, int size, int y, int x)
{
	int	i;

	i = 0;
	while (i < size && tab[i][x] != 0)
	{
		if (i != y)
			if (tab[i][x] == tab[y][x])
				return (0);
		i++;
	}
	i = 0;
	while (i < size && tab[y][i] != 0)
	{
		if (i != x)
			if (tab[y][i] == tab[y][x])
				return (0);
		i++;
	}
	return (1);
}
