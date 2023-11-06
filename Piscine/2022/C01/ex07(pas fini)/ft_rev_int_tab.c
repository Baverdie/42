/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 03:26:15 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/18 05:35:30 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	temp;
	int	temp_size;

	temp_size = size--;
	a = 0;
	size--;
	while(a != size)
	{
		temp = tab[size];
		tab[size] = tab[a];
		tab[a] = temp;
		printf("%d, %d, %d | ", tab[a], a, size);
		a++;
		size--;
	}
	a = 0;
	while (a <= temp_size)
	{
		printf("%d", tab[a]);
		a++;
	}
}

int	main(void)
{
	int tab[5] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(tab, 5);
}
