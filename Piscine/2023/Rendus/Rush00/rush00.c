/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:03:41 by cblonde           #+#    #+#             */
/*   Updated: 2023/07/15 15:15:23 by hdalessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_cnd_start_end(int a, int b, int i, int j)
{
	if (i == 0 && (j == 0 || j == a - 1))
	{
		ft_putchar('o');
		if (j == a - 1 || j == 1)
			ft_putchar('\n');
	}
	else if (i == b - 1 && (j == 0 || j == a - 1))
	{
		ft_putchar('o');
		if (j == a - 1 || j == 1)
			ft_putchar('\n');
	}
	else
	{
		ft_putchar('-');
	}
}

void	ft_other(int a, int j)
{
	if (j == 0 || j == a - 1)
	{
		ft_putchar('|');
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
