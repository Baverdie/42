/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:19:55 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 23:22:04 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

t_error	ft_atoui(char *str, unsigned int *result)
{
	long long int	total;
	char			*p_str;

	p_str = str;
	total = 0;
	while (*str && ft_isspace(*str))
		str++;
	if ((*str == '+' || *str == '-'))
	{
		if (*str - 1 == '-')
		{
			free(p_str);
			return (ft_errord("Invalid sign on unsigned integer."));
		}
		str++;
	}
	while (*str++)
		total = total * 10 + (*(str - 1) - '0');
	free(p_str);
	if (total < 0 || total > UINT_MAX)
		return (ERROR);
	*result = ((unsigned int)total);
	return (OK);
}

t_error	ft_parse_uint(char *str, unsigned int *result)
{
	long long int	total;
	char			*p_str;

	total = 0;
	p_str = str;
	while (*p_str++)
		if (!ft_isdigit(*(p_str - 1)))
			return (ft_error("Malformed unsigned integer."));
	while (*str++)
		total = total * 10 + (*(str - 1) - '0');
	if (total < 0 || total > UINT_MAX)
		return (ft_error("Invalid size for unsigned integer."));
	*result = ((unsigned int)total);
	return (OK);
}

char	*ft_fill(char *buffer, size_t size, char value)
{
	char	*p_buffer;

	p_buffer = buffer;
	while (size--)
		*buffer++ = value;
	return (p_buffer);
}

char	*ft_fill_trimmed(char *buffer, char *str)
{
	int	strlen;
	int	i;
	int	j;

	i = 0;
	while (*str)
	{
		j = 0;
		strlen = 0;
		while (*str && ft_isspace(*str))
			str++;
		while (*str && !ft_isspace(*str))
		{
			strlen++;
			str++;
		}
		if (j < strlen)
		{
			ft_strncat(buffer, str - strlen, strlen);
			buffer[i + strlen] = ' ';
			i += strlen + 1;
		}
	}
	return (buffer);
}

char	*ft_trim(char *str)
{
	size_t	size;
	char	*p_str;
	char	*buffer;

	size = -1;
	p_str = str;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str)
			size++;
		while (*str && !ft_isspace(*str))
		{
			size++;
			str++;
		}
	}
	if (!(size + 1))
		return (NULL);
	buffer = ft_fill(malloc((size + 1) * sizeof(char)), (size + 1), 0);
	buffer = ft_fill_trimmed(buffer, p_str);
	buffer[size] = 0;
	free(p_str);
	return (buffer);
}
