/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:06:11 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/27 13:45:35 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (s1[i] - s2[i] > 0)
		return (1);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_sort_int_tab(int *tab, int size)
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
	return (tab);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		k;
	char	temp;

	i = 1;
	k = 0;
	temp = 0;
	while (j < argc - 1)
	{
		i = 0;
		while (i <= argc - 2 - j)
		{
			if (ft_strcmp(&*argv[i], &*argv[i + 1]) == 1)
			{
				while (argv[i][k] || argv[i + 1][k])
				{
					temp = argv[i][k];
					argv[i][k] = argv[i + 1][k];
					argv[i + 1][k] = temp;
					k++;
				}
			}
			i++;
		}
		j++;
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
