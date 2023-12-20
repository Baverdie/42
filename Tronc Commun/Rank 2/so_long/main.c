/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:41:31 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/20 18:44:37 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		result_init;

	if (argc != 2)
		return (EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	data->file_name = argv[1];
	result_init = init(data);
	if (result_init != 0)
	{
		print_errors(result_init, data);
		if (result_init != 4)
		{
			ft_free(data->map);
			if (data->flood != NULL)
				ft_free(data->flood);
		}
		free(data->pos);
		free(data);
		return (EXIT_FAILURE);
	}
	ft_printf("T'es trop fort !\n");
	return (EXIT_SUCCESS);
}
