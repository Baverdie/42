/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:56 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/22 11:06:58 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

void	ft_putnbr(int n)
{
	// printf("n = %d\n", n);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if ((n / 10) > 0)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_check_flags(const char *s, int i, va_list ap)
{
	if (s[i] == '%')
	{
		i++;
		if (s[i] == 'c')
			ft_putchar(va_arg(ap, int));
		else if (s[i] == 's')
			ft_putstr(va_arg(ap, char *));
		else if (s[i] == 'p')
			ft_putnbr(va_arg(ap, int));
		else if (s[i] == 'd' || s[i] == 'i')
			ft_putnbr(va_arg(ap, int));
		else if (s[i] == '%')
			ft_putchar('%');
		else
			ft_putchar(s[i]);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_check_flags(s, i, ap);
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
	i = ft_printf("Hello %d %s !\n", 2, "World");
	printf("i = %d\n", i);
	return 0;
}
