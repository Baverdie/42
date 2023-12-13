/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:15:50 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/16 20:29:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_cnd_start_end(int a, int b, int i, int j)
{
	if (j == 0 && (i == 0 || i == b - 1))
	{
		ft_putchar('A');
		if (a == 1 || a == j - 1)
			ft_putchar('\n');
	}
	else if (j == a - 1 && (i == 0 || i == b - 1))
	{
		ft_putchar('C');
		if (i == b - 1 || i == 0)
			ft_putchar('\n');
	}
	else
	{
		ft_putchar('B');
	}
}

void	ft_other(int a, int j)
{
	if (j == 0 || j == a - 1)
	{
		ft_putchar('B');
		if (j == a - 1)
			ft_putchar('\n');
	}
	else
		ft_putchar(' ');
}

void	rush(int a, int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < b)
	{
		while (j < a)
		{
			if (i == 0 || i == b - 1)
			{
				ft_cnd_start_end(a, b, i, j);
			}
			else
			{
				ft_other(a, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
