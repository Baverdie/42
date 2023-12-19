/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:10:38 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/19 18:22:30 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_errors(int errors)
{
	ft_printf("\033[0;31mError\033[0m\n", 1);
	if (errors == 1)
		ft_printf("Error detected\n", 1);
	else if (errors == 2)
		ft_printf("No valid path found\n", 1);
	else if (errors == 3)
		ft_printf("Invalid map\n", 1);
	else if (errors == 4)
		ft_printf("Player not found\n", 1);
	else if (errors == 5)
		ft_printf("Invalide file\n", 1);
}