/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:43:01 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/11 13:21:44 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MacroLibX/includes/mlx.h"
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"

# define WIDTH (data->nb_cols + 1) * 64
# define HEIGHT data->nb_rows * 64

# define TITLE_ERROR "\033[0;31mError\033[0m\n"
# define INVALID_EXTENSION "Invalid extension\n"
# define ERROR_LABDA "Error detected\n"
# define MORE_FILE "Too many arguments detected\n"
# define NO_FILE "Missing file\n"
# define INVALID_FILE "Invalid file\n"
# define INVALID_MAP "Invalid map\n"
# define PLAYER_MISSING "Player not found\n"
# define PLAYER_MULTIPLE "Multiple players found\n"
# define EXIT_MISSING "Exit not found\n"
# define EXIT_MULTIPLE "Multiple exits found\n"
# define COL_ERROR "Collectible not found\n"
# define NO_PATH "No valid path found\n"
# define INVALID_NO_PATH "Invalid map and no valid path found\n"

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

typedef struct	s_textures {
	void	*player;
	void	*exit;
	void	*wall;
	void	*collectible;
}	t_textures;

typedef struct	s_mlx {
	void	*mlx;
	void	*window;
	int		img_size;
	struct s_textures	*img;
}	t_mlx;

// PARSE
	//handling
int		init(t_data *data);
int		errors_map(t_data *data);
	//sort map
int		read_map(t_data *data);
int		parse_map(t_data *data);
	//check
int		check_errors(t_data *data);
int		check_path(t_data *data);
void	flood(int x, int y, t_data *data, int dir);
int		pos_data(t_data *data);

// GRAPHIQUE
int		so_long(t_data *data);

// UTILS
	// free
void	ft_free(char **tab);
void	free_all(t_data *data);

	//print
void	print_map_full(char **map); //delete
void	print_map_errors(t_data *data);
void	print_path_map(t_data *data, int x, int y);
int		ft_print_errors(char *err);

	//copy
void	copy_map(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);

#endif