/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:43:01 by basverdi          #+#    #+#             */
/*   Updated: 2023/12/20 12:17:12 by basverdi         ###   ########.fr       */
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
}	t_game_positions;

typedef struct s_data {
	int		nb_rows;
	int		nb_cols;
	int		fd;
	char	*file_name;
	char	**map;
	char	**flood;
	struct s_game_positions	*pos;
}	t_data;

# define WIDTH 1920
# define HEIGHT 1080



// check fonctions

int	check_errors(t_data *data);
int	check_path(t_data *data);
int	init_map(t_data *data);
void	flood(int x, int y, t_data *data, int dir);

// utils fonctions

void	copy_map(t_data *data);
void	print_map(char	**map);
void	print_map_x(int posx, int posy, char **map);
void	print_errors(int errors);
void	ft_free(char **tab);

#endif