/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:37:01 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/23 13:04:26 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(char **tab)
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

void	ft_free_mobs(t_data *data)
{
	while (data->counter_mob > 0)
	{
		data->counter_mob--;
		free(data->mobs[data->counter_mob]);
	}
	free(data->mobs);
}

void	free_data(t_data *data)
{
	if (data->mobs)
		ft_free_mobs(data);
	if (data->flood)
		ft_free_map(data->flood);
	if (data->map)
		ft_free_map(data->map);
	free(data->pos);
	free(data);
}
