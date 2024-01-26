/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:56:21 by bedarenn          #+#    #+#             */
/*   Updated: 2023/07/23 19:47:23 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int	malloc_all_tab(int ***arg, int ***tab, char *argv)
{
	int	size;

	size = test_arg(argv);
	if (size == 0)
		return (0);
	*arg = malloc_arg(argv, size);
	if (!arg)
		return (0);
	*tab = malloc_tab(size);
	if (!*tab)
	{
		free_tab(*arg, 4);
		return (0);
	}
	return (size);
}

int	main(int argc, char **argv)
{
	int	size;
	int	**arg;
	int	**tab;

	if (argc != 2)
		return (error());
	size = malloc_all_tab(&arg, &tab, argv[1]);
	if (size == 0)
		return (error());
	if (!algo(tab, arg, size, 0))
	{
		free_tab(arg, 4);
		free_tab(tab, size);
		return (error());
	}
	print_tab(tab, size);
	free_tab(arg, 4);
	free_tab(tab, size);
	return (0);
}
