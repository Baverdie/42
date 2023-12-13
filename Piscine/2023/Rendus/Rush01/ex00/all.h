/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:35:40 by bedarenn          #+#    #+#             */
/*   Updated: 2023/07/23 19:47:26 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		error(void);

int		check_arg_column_top(int **tab, int **arg, int coord, int x);
int		check_arg_column_bot(int **tab, int **arg, int coord, int x);
int		check_arg_line_left(int **tab, int **arg, int coord, int y);
int		check_arg_line_right(int **tab, int **arg, int coord, int y);
int		check_occ(int **tab, int size, int y, int x);

int		test_arg(char *av);
int		**free_tab(int **tab, int size);
int		**malloc_arg(char *av, int size);
int		**malloc_tab(int size);

void	print_tab(int **tab, int size);

int		algo(int **tab, int **arg, int size, int coord);

#endif
