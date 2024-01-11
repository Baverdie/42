/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:56 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/11 01:15:27 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_check_flags(const char *s, int i, va_list arg)
{
	int j;

	j = 0;
	if (s[i] == '%')
		j += ft_putchar('%');
	else if (s[i] == 'c')
		j += ft_putchar(va_arg(arg, int));
	else if (s[i] == 's')
		j += ft_putstr(va_arg(arg, char *));
	else if (s[i] == 'p')
		j += ft_puthexaptr(va_arg(arg, long long int), "0123456789abcdef");
	else if (s[i] == 'd' || s[i] == 'i')
		j += ft_putnbr(va_arg(arg, int));
	else if (s[i] == 'u')
		j += ft_putnbr(va_arg(arg, unsigned int));
	else if (s[i] == 'x')
		j += ft_puthexa(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (s[i] == 'X')
		j += ft_puthexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else
		j += ft_putchar(s[i]);
	return (j);
}

int	ft_printf(const char *s, ...)
{
	va_list arg;
	int i;
	int j;

	i = 0;
	j = 0;
	va_start(arg, s);
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			j += ft_check_flags(s, i, arg);
		}
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (j);
}

int main(void)
{
	ft_printf("Hello %s\n", "World");
	ft_printf("Hello %c\n", 'W');
	ft_printf("Hello %d\n", 42);
	ft_printf("Hello %i\n", 42);
	ft_printf("Hello %u\n", 42);
	ft_printf("Hello %x\n", 42);
	ft_printf("Hello %X\n", 42);
	ft_printf("Hello %p\n", 42);
	return (0);
}