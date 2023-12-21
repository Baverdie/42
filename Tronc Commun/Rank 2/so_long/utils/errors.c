/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:10:38 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/21 17:01:22 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_debug(int code, t_data *data)
{
	if (code == 2)
		print_map(data, code);
	if (code == 5 || code == 6 || code == 7)
	{
		data->errorx = -1;
		data->errory = -1;
		print_map(data, code);
	}
}

void	print_errors_map(int errors, t_data *data)
{
	if (errors == 5 || errors == 6 || errors == 7)
		ft_printf("No valid path found\n", 1);
	else if (errors == 2)
	{
		data->flood = ft_calloc(data->nb_rows + 1, sizeof(char *));
		if (!data->flood)
			return ;
		copy_map(data);
		flood(data->pos->player_row, data->pos->player_col, data, 0);
		if (check_path(data) != 0)
			ft_printf("Invalid map and no valid path found\n", 1);
		else
			ft_printf("Invalid map\n", 1);
	}
}

void	print_errors(int errors, t_data *data)
{
	ft_printf("\033[0;31mError\033[0m\n", 1);
	if (errors == 1)
		ft_printf("Error detected\n", 1);
	else if (errors == 2 || errors == 5 || errors == 6 || errors == 7)
		print_errors_map(errors, data);
	else if (errors == 3)
		ft_printf("Player not found\n", 1);
	else if (errors == 8)
		ft_printf("Exit not found\n", 1);
	else if (errors == 9)
		ft_printf("Collectible not found\n", 1);
	else if (errors == 4)
		ft_printf("Invalide file\n", 1);
	ft_debug(errors, data);
}
