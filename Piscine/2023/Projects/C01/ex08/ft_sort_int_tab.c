/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:40:58 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/15 23:41:36 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (tab[j])
	{
		i = 0;
		while (i <= size - 2 - j)
		{
			if (tab[i] >= tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j++;
	}
}
