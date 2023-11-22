/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:56 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/22 12:53:29 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	return (0);
}

static int	ft_check_flags(const char *s, int i, va_list ap)
{
	int	j;

	j = 0;
	if (s[i] == '%')
	{
		i++;
		if (s[i] == 'c')
			ft_putchar(va_arg(ap, int));
		else if (s[i] == 's')
			j += ft_putstr(va_arg(ap, char *)) - 1;
		else if (s[i] == 'p')
			j += ft_putnbr(va_arg(ap, int)) - 1;
		else if (s[i] == 'd' || s[i] == 'i')
			ft_putnbr(va_arg(ap, int));
		else if (s[i] == '%')
			ft_putchar('%');
		else
			ft_putchar(s[i]);
	}
	printf("check = %d\n", j);
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
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			j += ft_check_flags(s, i, ap);
			i++;
		}
		else
			ft_putchar(s[i]);
		i++;
		j++;
	}
	va_end(ap);
	return (j);
}

int	main()
{
	int	i;

	i = 0;
	i = ft_printf("%d\n", 123);
	printf("i = %d\n", i);
	return 0;
}
