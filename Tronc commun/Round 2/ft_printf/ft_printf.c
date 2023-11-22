/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:56 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/22 16:50:12 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_flags(const char *s, int i, va_list ap)
{
	int	j;

	j = 0;
	if (s[i] == '%')
	{
		i++;
		if (s[i] == 'c')
			j += ft_putchar(va_arg(ap, int));
		else if (s[i] == 's')
			j += ft_putstr(va_arg(ap, char *));
		else if (s[i] == 'p')
			j += ft_puthexap(va_arg(ap, long long int), "0123456789abcdef");
		else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
			j += ft_putnbr(va_arg(ap, long long int));
		else if (s[i] == 'x')
			j += ft_puthexa(va_arg(ap, int), "0123456789abcdef");
		else if (s[i] == 'X')
			j += ft_puthexa(va_arg(ap, int), "0123456789ABCDEF");
		else if (s[i] == '%')
			j += ft_putchar('%');
		else
			j += ft_putchar(s[i]);
	}
	return (j);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, s);
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			j += ft_check_flags(s, i, ap);
			i ++;
		}
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (j);
}
