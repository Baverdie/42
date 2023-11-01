/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:25:24 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 23:26:00 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "io.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_error	ft_parse_args(int argc, char **argv, t_params *params)
{
	if (argc == 2)
	{
		params->dict = "numbers.dict";
		if (ft_parse_uint(argv[1], &params->nbr))
			return (ERROR);
	}
	else if (argc == 3)
	{
		params->dict = argv[1];
		if (ft_parse_uint(argv[2], &params->nbr))
			return (ERROR);
	}
	else if (argc == 1)
	{
		if (ft_handle_stdin(params))
			return (ERROR);
	}
	else
	{
		params->dict = NULL;
		params->nbr = 0;
	}
	return (OK);
}

char	*ft_dialog(char *prompt, char *default_value)
{
	char	*buffer;
	ssize_t	size;

	buffer = malloc(64);
	ft_putstr(prompt);
	if (default_value)
	{
		ft_putstr(" (default: '");
		ft_putstr(default_value);
		ft_putstr("')");
	}
	ft_putstr(": ");
	size = read(0, buffer, 64);
	buffer[size - 1] = 0;
	if (size == 1 && default_value)
		ft_strcpy(buffer, default_value);
	return (buffer);
}

t_error	ft_handle_stdin(t_params *params)
{
	char	*dict;
	char	*nbr;

	dict = ft_dialog("📖 Choose a dictionnary file", "numbers.dict");
	nbr = ft_dialog("🔢 Input a number", "0");
	if (!nbr)
		return (ft_error("Invalid number."));
	if (ft_parse_uint(nbr, &params->nbr))
		return (ERROR);
	params->dict = dict;
	free(nbr);
	return (OK);
}
