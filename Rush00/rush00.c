/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mauffray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:30:11 by mauffray          #+#    #+#             */
/*   Updated: 2022/07/17 17:05:07 by mauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_check_pos(int a, int b, int col, int lig)
{
	if (lig == 0 || lig == b - 1)
	{
		if (col == 0)
			ft_putchar('o');
		else if (col == a - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (col == 0 || col == a - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int a, int b)
{
	int	lig;
	int	col;

	lig = 0;
	while (lig < b)
	{
		col = 0;
		while (col < a)
		{
			ft_check_pos(a, b, col, lig);
			col++;
		}
		if (a > 0)
			ft_putchar('\n');
		lig++;
	}
}
