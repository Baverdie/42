/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:43:01 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/18 16:36:55 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "ft_libft/libft.h"

typedef struct s_data {
	int		nb_rows;
	int		nb_cols;
	int		fd;
	char	*file_name;
	char	**map;
	char	**flood;
}	t_data;

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_game_positions {
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
}	t_game_positions;

int	check_errors(t_data *data);
int	init_map(t_data *data);
void	flood(int x, int y, int new_col, t_data *data);

#endif