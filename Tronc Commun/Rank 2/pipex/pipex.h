/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:15 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/01 15:37:20 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# define TITLE_ERROR "\033[0;31mError\033[0m\n"
# define ARGS_ERROR "Pipex only takes 4 arguments !\n"
# define PIPE_ERROR "Pipe failed\n"
# define FORK_ERROR "Fork failed\n"
# define CMD_ERROR "Command not found\n"
# define ARG_NULL "Error arguments\n"

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
void	get_fds(t_data *data, char **argv);
char	*get_path(char **envp, char *cmd);
//UTILS
	//print
int		ft_print_error_return(char *err);
	//free
void	ft_free(char **tab);
void	ft_close(t_data data);

#endif