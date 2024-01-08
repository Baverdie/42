/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:46:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/08 16:29:34 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

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

void	free_all(t_data *data)
{
	if (data->flood)
		ft_free_map(data->flood);
	if (data->map)
		ft_free_map(data->map);
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