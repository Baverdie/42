/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:56:24 by bedarenn          #+#    #+#             */
/*   Updated: 2023/07/23 22:33:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include <stdlib.h>

int	test_arg(char *av)
{
	int	size;
	int	len;

	len = ft_strlen(av);
	if ((len + 1) % 8 != 0)
		return (0);
	size = (len + 1) / 8;
	if (size > 6)
		return (0);
	while (len--)
	{
		if (len % 2 == 0)
		{
			if (av[len] <= '0' || av[len] > size + '0')
				return (0);
		}
		else
		{
			if (av[len] != ' ')
				return (0);
		}
	}
	return (size);
}

int	**free_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	**malloc_arg(char *av, int size)
{
	int	**arg;
	int	i;
	int	j;

	arg = malloc(sizeof(int *) * 4);
	if (!arg)
		return (0);
	i = 0;
	while (i < 4)
	{
		arg[i] = malloc(sizeof(int) * size);
		if (!arg[i])
		{
			free_tab(arg, i);
			return (0);
		}
		j = 0;
		while (j < size)
		{
			arg[i][j] = av[(i * size * 2) + (j * 2)] - '0';
			j++;
		}
		i++;
	}
	return (arg);
}

int	**malloc_tab(int size)
{
	int	**tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(sizeof(int) * size);
		if (!tab[i])
		{
			free_tab(tab, i);
			j = 0;
			while (j < size)
			{
				tab[i][j] = 0;
				j++;
			}
			return (0);
		}
		i++;
	}
	return (tab);
}
