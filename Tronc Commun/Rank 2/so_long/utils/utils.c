/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:46:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/15 13:05:11 by basverdi         ###   ########.fr       */
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
	ft_printf("%s%s", TITLE_ERROR, err);
	return (0);
}

int	init_vars(t_mlx *mlx, t_data *data)
{
	mlx->img = ft_calloc(1, sizeof(t_textures));
	if (!mlx || !mlx->img)
		return (ft_print_errors(ERROR_LABDA));
	mlx->img_size = 32;
	mlx->data = data;
	mlx->nb_move = 0;
	mlx->nb_col = 0;
	mlx->nb_frames = 0;
	mlx->data->nb_0 -= 2;
	mlx->data->pos->ref_mob_score = 10;
	mlx->data->pos->ref_col_score = 5;
	mlx->data->pos->ref_exit_score = 1;
	mlx->data->dash_count = 0;
	mlx->score = 0;
	mlx->dir_player = 0;
	return (0);
}

int	ft_str_display(t_mlx *mlx)
{
	char	*movs;
	char	*nb_moves;
	char	*score;
	char	*nb_score;
	int		width;

	width = (mlx->data->nb_cols - 1) * 32;
	nb_moves = ft_itoa(mlx->nb_move);
	movs = ft_strjoin("Mouvements : ", nb_moves);
	nb_score = ft_itoa(mlx->score);
	score = ft_strjoin("Score : ", nb_score);
	mlx_string_put(mlx->mlx, mlx->window, 32, 25, 0xffFFFFFF, movs);
	mlx_string_put(mlx->mlx, mlx->window, width - 32, 25, 0xffFFFFFF, score);
	free(nb_score);
	free(nb_moves);
	free(movs);
	free(score);
	return (0);
}

void	ft_print_end(t_mlx *mlx)
{
	if (mlx->nb_col == mlx->data->pos->obj && \
	mlx->data->pos->player_col == mlx->data->pos->exit_col && \
	mlx->data->pos->player_row == mlx->data->pos->exit_row)
		ft_printf("\n\033[1;32mYou Win !\n\033[0m");
	else
		ft_printf("\n\033[1;31mGame over !\n\033[0m");
	ft_printf("\033[1;37mFinal Score : %d \033[0m\nTotal Mouvements : %d\n",
		mlx->score, mlx->nb_move);
}
