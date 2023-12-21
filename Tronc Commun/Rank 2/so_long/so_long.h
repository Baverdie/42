/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:43:01 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/21 18:10:05 by basverdi         ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"

typedef struct s_game_positions {
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
	int	obj;
}	t_game_positions;

typedef struct s_data {
	int		nb_rows;
	int		nb_cols;
	int		fd;
	char	*file_name;
	char	**map;
	char	**flood;
	int		errorx;
	int		errory;
	struct s_game_positions	*pos;
}	t_data;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

# define WIDTH data->nb_cols * 64
# define HEIGHT data->nb_rows * 64

// check fonctions

int		init(t_data *data);
int		init_map(t_data *data);

int		pos_data(t_data *data);
int		read_map(t_data *data);
int		parse_map(t_data *data);

int		check_errors(t_data *data);
int		check_path(t_data *data);
void	flood(int x, int y, t_data *data, int dir);

// game fonction

int	so_long(t_data *data);

// utils fonctions

void	copy_map(t_data *data);
void	print_map(t_data *data, int err);
void	print_errors(int errors, t_data *data);
void	ft_free(char **tab);

#endif