/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow_better.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:56:35 by bastienverd       #+#    #+#             */
/*   Updated: 2024/05/14 12:06:34 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	t_bool ft_is_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static	t_bool is_nb(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (s && *s)
	{
		if (ft_is_nb(*s))
			s += 1;
		else
			return (FALSE);
	}
	return (TRUE);
}

static	t_bool check_nb_same_len(char *s, char *max, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (*(s + i) > max[i])
			return (TRUE);
		i += 1;
	}
	return (FALSE);
}

static int ft_check_overflow(char *s, char *min, char *max, int len)
{
	int	neg;
	int	i;

	neg = 0;
	i = 0;
	if (!is_nb(s))
		return (TRUE);
	neg = (*s == '-') * -1 + (*s == '+') * 1;
	while (s && (*s == '0' || *s == '+' || *s == '-'))
		s++;
	while (s && *(s + i))
		i += 1;
	if (i > len)
		return (TRUE);
	if (i == len && neg != -1)
		return (check_nb_same_len(s, max, len));
	else if (i == len)
		return (check_nb_same_len(s, min, len));
	return (FALSE);
}

t_bool	ft_overflow(char *s, ...)
{
	int		i;
	va_list	arg;
	t_bool	is_it;

	i = 0;
	va_start(arg, s);
	if (s == NULL)
		return (TRUE);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (s[i + 1] == 'i')
				is_it = ft_check_overflow(va_arg(arg, char *), INTMIN, INTMAX, \
					ft_strlen(INTMAX));
			else if (s[i + 1] == 'l' && s[i + 2] == 'l')
				is_it = ft_check_overflow(va_arg(arg, char *), LLMAX, LLMIN, \
					ft_strlen(LLMAX));
		}
		if (is_it)
			return (is_it);
		i++;
	}
	va_end(arg);
	return (is_it);
}
