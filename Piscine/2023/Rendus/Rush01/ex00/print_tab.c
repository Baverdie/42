/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:14:10 by ttrave            #+#    #+#             */
/*   Updated: 2023/07/23 19:47:25 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include <unistd.h>

void	print_line(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(tab[i] + '0');
		i++;
		if (i < size)
			ft_putchar(' ');
	}
}

void	print_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		print_line(tab[i], size);
		i++;
		ft_putchar('\n');
	}
}
