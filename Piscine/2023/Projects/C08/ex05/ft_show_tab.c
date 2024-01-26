/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:40:06 by basverdi          #+#    #+#             */
/*   Updated: 2023/08/02 16:27:38 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;
	char	*str;
	int		size;

	i = 0;
	while (par[i].str != 0)
	{
		str = par[i].str;
		size = par[i].size;
		ft_putstr(str);
		ft_putchar('\n');
		ft_putnbr(size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
