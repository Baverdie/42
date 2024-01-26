/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:25:56 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/30 22:18:23 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_hundred(t_values *tab, unsigned long long arg)
{
	unsigned long long	nb;
	unsigned long long	nb2;
	unsigned long long	count;
	int					i;

	i = 0;
	count = 10;
	nb = arg;
	while (nb >= 100)
	{
		nb2 = nb % 100;
		nb = nb / 100;
		count *= 10;
	}
	ft_print_nbr(tab, nb);
	ft_putstr(" ");
	while (tab[i].value != count)
		i++;
	ft_putstr(tab[i].value_str);
	ft_putstr(" ");
	if (nb2 != 0)
		ft_print_nbr(tab, nb2);
}

long long	*ft_long_nbr(unsigned long long arg)
{
	int					count;
	long long			*tab;
	int					i;
	unsigned long long	nb;

	count = 0;
	i = 0;
	nb = arg;
	while (arg >= 10)
	{
		arg /= 10;
		count++;
	}
	count++;
	tab = malloc(count * sizeof(int));
	while (count > 0)
	{
		tab[i] = nb % 1000;
		nb /= 1000;
		count -= 3;
		i++;
	}
	tab[i] = -1;
	return (tab);
}

int	ft_tablen(long long *tab)
{
	int	i;
	int	nb;

	i = 1;
	nb = 1;
	while (tab[i] != -1)
	{
		i++;
		nb *= 1000;
	}
	return (nb);
}

void	ft_check_nb(t_values *tab, unsigned long long arg)
{
	int			j;
	long long	*nb;
	int			size;

	j = 0;
	nb = ft_long_nbr(arg);
	size = ft_tablen(nb);
	while (nb[j] != -1)
		j++;
	j--;
	while (j >= 0)
	{
		if (nb[j] != 0)
		{
			ft_print_nbr(tab, nb[j]);
			ft_putstr(" ");
			if (size > 100)
			{
				ft_print_nbr(tab, size);
				ft_putstr(" ");
			}
		}
	j--;
	size /= 1000;
	}
}

void	ft_print_nbr(t_values *tab, unsigned long long arg)
{
	int			i;

	i = 1;
	if ((arg <= 20 || arg % 10 == 0) && arg != 100)
	{
		while (tab[i].value != arg && ft_strcmp(tab[i].value_str, "end") != 0)
			i++;
		if (tab[i].value == arg && tab[i].value_str != NULL)
			ft_putstr(tab[i].value_str);
		else
			ft_print_hundred(tab, arg);
	}
	else if (arg > 20)
	{
		if (arg > 999)
			ft_check_nb(tab, arg);
		else if (arg > 99)
			ft_print_hundred(tab, arg);
		else
		{
			ft_print_nbr(tab, arg - (arg % 10));
			ft_putstr(" ");
			ft_putstr(tab[arg % 10 + 1].value_str);
		}
	}
}
