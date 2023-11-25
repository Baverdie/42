/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:56 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/24 13:40:50 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flags(const char *s, int i, va_list ap)
{
	int	j;

	j = 0;
	if (s[i] == '%')
	{
		i++;
		if (s[i] == '%')
			j += ft_putchar('%');
		else if (s[i] == 'c')
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
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			j += ft_putchar(va_arg(ap, int));
			i ++;
		}
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (j);
}

int main(){

	ft_printf("%c %c\n", 'z', 'a');
	printf("%c %c", 'z', 'a');
	return (0);
}
