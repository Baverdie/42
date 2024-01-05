/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:41:31 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/05 14:16:20 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 2)
		return (ft_print_errors(MORE_FILE));
	else if (argc < 2)
		return (ft_print_errors(NO_FILE));
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_print_errors(ERROR_LABDA));
	data->file_name = argv[1];
	if (init(data) == 0)
	{
		free_all(data);
		return (0);
	}
	so_long(data);
	return (EXIT_SUCCESS);
}