/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:25 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/27 16:00:44 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexaptr(unsigned long long ptr, char *base)
{
	int	cntr;

	cntr = 0;
	if (ptr == 0)
	{
		cntr += ft_putstr("(nil)");
		return (cntr);
	}
	cntr += ft_putstr("0x");
	if (ptr < 16)
		cntr += ft_putchar(base[ptr]);
	else
	{
		cntr += ft_puthexa(ptr / 16, base);
		cntr += ft_putchar(base[ptr % 16]);
	}
	return (cntr);
}
