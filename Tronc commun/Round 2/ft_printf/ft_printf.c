/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:00:56 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/21 21:19:13 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_check_flags(const char *s, int i, va_list ap)
{
	(void)s;
	(void)i;
	(void)ap;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
			ft_check_flags(s, i, ap);
		else
			ft_putstr(s);
		i++;
	}
	va_end(ap);
	return 0;
}

int main()
{
	ft_printf("Hello World!");
	return 0;
}