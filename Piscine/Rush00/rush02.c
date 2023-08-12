/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mauffray <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:30:11 by mauffray          #+#    #+#             */
/*   Updated: 2022/07/16 11:05:46 by mauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_check_pos(int a, int b, int col, int lig)
{
	if (lig == 0)
	{
		if (col == 0 || col == a - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (lig == b - 1)
	{
		if (col == 0 || col == a - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (col == 0 || col == a - 1)
			ft_putchar('B');
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
