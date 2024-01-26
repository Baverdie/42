/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:11:44 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 09:17:29 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

void	ft_putnbr(int nb)
{
	int		is_min_int;
	int		rest;
	char	buffer;

	buffer = '-';
	if (nb < 0)
		write(1, &buffer, 1);
	is_min_int = (nb == INT_MIN);
	if (is_min_int)
		nb += 1;
	if (nb < 0)
		nb = ~(nb - 1);
	if (nb > 9)
		ft_putnbr(nb / 10);
	rest = nb % 10;
	if (is_min_int)
		rest += 1;
	buffer = rest + '0';
	write(1, &buffer, 1);
}
