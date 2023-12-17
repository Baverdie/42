/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:41:31 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/17 13:41:55 by basverdi         ###   ########.fr       */
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
	if (init_map(data) == 0)
	{
		printf("Ta mere la chienne\n");
		free(data);
		return (EXIT_FAILURE);
	}
	printf("T'es trop fort !\n");
	return (EXIT_SUCCESS);
}
