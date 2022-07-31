/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:13:10 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 23:24:10 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "error.h"
#include "input.h"
#include "libft.h"
#include "parser.h"
#include "print.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_params	params;
	t_dict		dict;
	int			fd;

	if (ft_parse_args(argc, argv, &params))
		return (0);
	if (!params.dict)
		return (0);
	fd = open(params.dict, O_RDONLY);
	if (fd == -1)
		return (ft_errord("Couldn't read file."));
	close(fd);
	dict.size = 0;
	ft_dict_allocate(&dict, 0);
	ft_parse_dict(&dict, params.dict);
	ft_print_number(&dict, params.nbr);
	ft_putstr("\n");
	ft_dict_free(&dict);
	if (argc == 1)
		free(params.dict);
	return (OK);
}
