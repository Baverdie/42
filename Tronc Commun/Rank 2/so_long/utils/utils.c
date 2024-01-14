/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:46:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/14 07:23:31 by basverdi         ###   ########.fr       */
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

int	ft_print_errors(char *err)
{
	ft_printf("%s%s", TITLE_ERROR, err);\
	return(0);
}

int	init_vars(t_mlx *mlx, t_data *data)
{
	mlx->data = data;
	mlx->nb_move = 0;
	mlx->nb_col = 0;
	mlx->nb_frames = 0;
	mlx->data->nb_0 -= 2;
	mlx->data->pos->ref_mob_score = 10;
	mlx->data->pos->ref_col_score = 5;
	mlx->score = 0;
	return (0);
}

int	ft_str_display(t_mlx *mlx)
{
	char	*movs;
	char	*nb_moves;
	char	*score;
	char	*nb_score;
	int		width;

	width = (mlx->data->nb_cols - 1) * 64 - 32;
	nb_moves = ft_itoa(mlx->nb_move);
	movs = ft_strjoin("Mouvements : ", nb_moves);
	nb_score = ft_itoa(mlx->score);
	score = ft_strjoin("Score : ", nb_score);
	mlx_string_put(mlx->mlx, mlx->window, 32, 25, 0x00FFFFFF, movs);
	mlx_string_put(mlx->mlx, mlx->window, width, 25, 0x00FFFFFF, score);
	free(nb_moves);
	free(movs);
	return (0);
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