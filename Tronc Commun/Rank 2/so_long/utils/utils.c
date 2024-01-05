/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:46:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/05 14:47:55 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(t_data *data)
{
	if (data->flood)
		ft_free(data->flood);
	if (data->map)
		ft_free(data->map);
	free(data->pos);
	free(data);
}

int	ft_print_errors(char *err)
{
	ft_printf("%s%s", TITLE_ERROR, err);\
	return(0);
}

void print_map_full(char **map)
{
	int	i;
	int	j;

	i = 0;
	printf("map:\n");
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}