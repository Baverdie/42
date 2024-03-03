/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:45 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/03 16:18:54 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child1(t_data data, char **av, char **envp)
{
	dup2(data.fd_in, STDIN_FILENO);
	dup2(data.pipe[1], STDOUT_FILENO);
	if (!av[2] || !*av[2])
	{
		ft_print_error_return(ARG_NULL);
		exit (1);
	}
	data.cmd = ft_split(av[2], ' ');
	data.cmd_path = get_path(envp, data.cmd[0]);
	if (data.cmd_path == NULL || access(data.cmd_path, F_OK))
	{
		ft_print_error_return(CMD_ERROR);
		ft_free(data.cmd);
		exit (1);
	}
	ft_close(data);
	execve(data.cmd_path, data.cmd, envp);
	free(data.cmd_path);
	ft_free(data.cmd);
}

void	child2(t_data data, char **av, char **envp)
{
	dup2(data.pipe[0], STDIN_FILENO);
	dup2(data.fd_out, STDOUT_FILENO);
	if (!av[3] || !*av[3])
	{
		ft_print_error_return(ARG_NULL);
		exit (1);
	}
	data.cmd = ft_split(av[3], ' ');
	data.cmd_path = get_path(envp, data.cmd[0]);
	if (data.cmd_path == NULL || access(data.cmd_path, F_OK))
	{
		ft_print_error_return(CMD_ERROR);
		ft_free(data.cmd);
		exit (1);
	}
	ft_close(data);
	execve(data.cmd_path, data.cmd, envp);
	free(data.cmd_path);
	ft_free(data.cmd);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac == 5)
	{
		get_fds(&data, av);
		if (pipe(data.pipe) == -1)
			ft_print_error_return(PIPE_ERROR);
		data.pid1 = fork();
		if (data.pid1 < 0)
			ft_print_error_return(FORK_ERROR);
		else if (data.pid1 == 0)
			child1(data, av, envp);
		data.pid2 = fork();
		if (data.pid2 < 0)
			ft_print_error_return(FORK_ERROR);
		else if (data.pid2 == 0)
			child2(data, av, envp);
		ft_close(data);
		waitpid(data.pid1, NULL, 0);
		waitpid(data.pid2, NULL, 0);
	}
	else
		ft_print_error_return(ARGS_ERROR);
	return (0);
}
