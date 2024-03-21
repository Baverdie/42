/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:56 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/21 19:42:07 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_format(const char c, va_list args)
{
	if (c == 'S')
		return (ft_putmultstr(va_arg(args, char **)));
	if (c == 'c')
		return (ft_putlchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putlstr(va_arg(args, char *)));
	if (c == 'u')
		return (ft_putlunbr(va_arg(args, unsigned int)));
	if (c == 'd' || c == 'i')
		return (ft_putlnbr(va_arg(args, int)));
	if (c == '%')
		return (ft_putlchar('%'));
	if (c == 'x')
		return (ft_putlhexa_low(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_putlhexa_up(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_putlpoint(va_arg(args, void *)));
	if (!c)
		return (0);
	return (ft_putlchar('%') + ft_putlchar(c));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s && *s)
	{
		if (*s == '%')
			len += ft_format(*(++s), args);
		else
			len += ft_putlchar(*s);
		s += 1;
	}
	va_end(args);
	return (len);
}
