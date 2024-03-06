/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:15 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/06 17:53:10 by basverdi         ###   ########.fr       */
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

typedef enum s_close_type
{
	CLOSE_FD,
	CLOSE_PIPE,
	CLOSE_STD,
	CLOSE_ALL,
	EXIT,
}	t_close_type;

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
void	ft_exit_error(char *err, t_data data);
void	ft_print_error(char *err);
	//free
void	ft_free(char **tab);
void	ft_close(t_data data, int nb, ...);
void	ft_close_pipe(t_data data);
void	ft_close_fd(t_data data);
void	ft_close_exit(void);
void	ft_close_all(t_data data);

#endif
