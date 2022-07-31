/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeverge <tdeverge@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:12:15 by tdeverge          #+#    #+#             */
/*   Updated: 2022/07/31 23:22:48 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"
#include "print.h"
#include <limits.h>

#define HIPHEN "-"
#define AND " and "
#define COMMA ", "

int	ft_direct_index_access(unsigned long nbr)
{
	unsigned int	count;

	if (nbr <= 20)
		return (1);
	if (nbr <= 100 && nbr % 10 == 0)
		return (1);
	count = 1000;
	while (count <= 1000000000)
	{
		if (nbr == count)
			return (1);
		count *= 1000;
		if (count == 0)
			break ;
	}
	return (0);
}

void	ft_print_number(t_dict *dict, unsigned long nbr)
{
	if (ft_dict_index(dict, nbr) != -1)
	{
		if (ft_direct_index_access(nbr))
		{
			if (nbr % 10 == 0 && nbr >= 100)
				ft_print_number(dict, 1);
			if (nbr % 10 == 0 && nbr >= 100)
				ft_putstr(" ");
			ft_putstr(ft_dict_get(dict, nbr));
			return ;
		}
	}
	if (nbr < 100)
	{
		ft_print_number(dict, (nbr / 10) * 10);
		ft_putstr(HIPHEN);
		ft_print_number(dict, nbr % 10);
		return ;
	}
	ft_handle_units(dict, nbr);
}

void	ft_handle_units(t_dict *dict, unsigned long nbr)
{
	int	unit;

	unit = dict->size;
	while (unit-- >= 0)
	{
		if (nbr < (long)dict->numbers[unit] * 1000 && (nbr
				/ dict->numbers[unit]) > 0
			&& ft_direct_index_access(dict->numbers[unit]))
		{
			ft_print_number(dict, (nbr / dict->numbers[unit]));
			ft_putstr(" ");
			ft_putstr(dict->values[unit]);
			if (nbr % dict->numbers[unit] < 100 && nbr
				% dict->numbers[unit] > 0)
				ft_putstr(AND);
			else if (nbr % dict->numbers[unit] != 0)
				ft_putstr(COMMA);
			if (nbr % dict->numbers[unit] != 0)
				ft_print_number(dict, nbr % dict->numbers[unit]);
			return ;
		}
	}
}
