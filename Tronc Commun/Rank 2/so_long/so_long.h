/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:43:01 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/24 23:55:21 by bastienverd      ###   ########.fr       */
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
# include <stdlib.h>
# include <time.h>

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
# define MISSING_TEXTURE "Missing textures\n"

typedef struct s_game_object {
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
	int	obj;
	int	nb_mobs;
	int	ref_mob_score;
	int	ref_col_score;
	int	ref_exit_score;
}	t_game_object;

typedef struct s_mob {
	int	id;
	int	pos_x;
	int	pos_y;
	int	initial_x;
	int	initial_y;
	int	tombstone;
	int	is_alive;
	int	dir;
}	t_mob;

typedef struct s_data {
	int						nb_rows;
	int						nb_cols;
	int						fd;
	char					*file_name;
	char					**map;
	char					**flood;
	int						errorx;
	int						errory;
	int						nb_0;
	int						dash_count;
	int						counter_mob;
	struct s_mob			**mobs;
	struct s_game_object	*pos;
}	t_data;

typedef struct s_textures {
	void	*player_left;
	void	*player_top;
	void	*player_right;
	void	*exit;
	void	*wall;
	void	*col;
	void	*ground;
	void	*mob_left;
	void	*mob_top;
	void	*mob_right;
	void	*tombstone;
}	t_textures;

typedef struct s_mlx {
	void				*mlx;
	void				*window;
	int					img_size;
	int					nb_move;
	int					nb_col;
	int					nb_frames;
	int					score;
	int					dir_player;
	struct s_data		*data;
	struct s_textures	*img;

}	t_mlx;

// PARSE
	// handling
int		init(t_data *data);
int		errors_map(t_data *data);
	// sort map
int		read_map(t_data *data);
int		parse_map(t_data *data);
	// check
int		check_errors(t_data *data);
int		check_path(t_data *data);
void	flood(int x, int y, t_data *data, int dir);
int		pos_data(t_data *data);

// GRAPHIQUE
int		so_long(t_data *data);
void	ft_event(t_mlx *mlx);
int		update(void *param);
	// check
int		check_best_dir(t_mlx *mlx);
	// move
void	ft_forward(t_mlx *mlx);
void	ft_left(t_mlx *mlx);
void	ft_backward(t_mlx *mlx);
void	ft_right(t_mlx *mlx);
int		ft_dash(t_mlx *mlx);

// UTILS
	// init
int		init_vars(t_mlx *mlx, t_data *data);
void	set_img(t_mlx *mlx);
	// score
int		add_score_y(t_data *data, int i, int x, int y);
int		add_score_x(t_data *data, int i, int x, int y);
	// free
void	ft_free(char **tab);
void	free_data(t_data *data);
void	ft_destroy(t_mlx *mlx);
	// print
void	print_map_errors(t_data *data);
void	print_path_map(t_data *data, int x, int y);
int		ft_print_errors(char *err);
int		ft_map(t_mlx *mlx);
int		ft_str_display(t_mlx *mlx);
int		ft_print_score(t_mlx *mlx, int nb_kill);
void	display_element(t_mlx *mlx, int i, int j);
void	display_mob(t_mlx *mlx, int i, int j);
void	ft_print_end(t_mlx *mlx);
void	print_map_mob(t_mlx *mlx);
int		ft_print_score(t_mlx *mlx, int nb_kill);
	// copy
void	copy_map(char **dest, char **src, int len);
int		ft_strcmp(const char *s1, const char *s2);

// MOB
int		init_mob(t_data *data, int counter_mob, int i, int j);
int		pos_mob(t_data *data);
int		move_mobs(t_data *data);
int		kill_mob(t_mlx *mlx, int y, int x);
int		count_mob(t_data *data);
int		lateral(t_data *data, t_mob *mob, int rd);
int		vertical(t_data *data, t_mob *mob, int rd);

#endif