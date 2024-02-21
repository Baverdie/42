/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:06:05 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/21 10:05:01 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define TITLE_ERROR "\033[0;31mError\033[0m\n"
# define ERROR_ARGS "Pipex only takes 4 arguments !"
# define ERROR_PIPE "Pipe failed"
# define ERROR_FORK "Fork failed"
# define ERROR_CMD "Command not found"

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	char	**cmd;
	char	*path;
	char	*cmd_path;
}	t_data;

//PIPEX
	//parsing
void	parse_args(char **av, char **envp);
void	get_fds(t_data *data, char **argv);
char	*get_path(char **envp, char *cmd);
//UTILS
	//print
void	ft_print_error(char *err);
int		ft_print_error_return(char *err);
	//free
void	ft_free(char **tab);
void	close_pipe(t_data *data);

# endif