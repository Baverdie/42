/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:41:31 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/20 11:20:19 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	data->file_name = argv[1];
	if (init_map(data) != 0)
	{
		print_errors(init_map(data));
		ft_free(data->map);
		ft_free(data->flood);
		free(data->pos);
		free(data);
		// printf("%s\n", data->map[0]);
		return (EXIT_FAILURE);
	}
	ft_printf("T'es trop fort !\n");
	return (EXIT_SUCCESS);
}
