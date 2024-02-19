/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:06:05 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/19 15:32:33 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_libft/libft.h"
# include <stdio.h>

# define TITLE_ERROR "\033[0;31mError\033[0m\n"
# define ERROR_ARGS "Pipex only takes 4 arguments !"

//PIPEX
	//parsing
int	parse_args(char **av, char **envp);
//UTILS
	//print
int	ft_print_error(char *err);
	//free
void	ft_free(char **tab);

# endif