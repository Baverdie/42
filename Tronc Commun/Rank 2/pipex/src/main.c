/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:45 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/26 17:59:25 by basverdi         ###   ########.fr       */
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
	if (data.cmd_path == NULL)
	{
		ft_print_error_return(ERROR_CMD);
		ft_free(data.cmd);
		exit (1);
	}
	close_pipe(data);
	execve(data.cmd_path, data.cmd, envp);
	close_std(data);
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
	if (data.cmd_path == NULL)
	{
		ft_print_error_return(ERROR_CMD);
		ft_free(data.cmd);
		exit (1);
	}
	close_pipe(data);
	execve(data.cmd_path, data.cmd, envp);
	close_std(data);
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
			ft_print_error_return(ERROR_PIPE);
		data.pid1 = fork();
		if (data.pid1 < 0)
			ft_print_error_return(ERROR_FORK);
		else if (data.pid1 == 0)
			child1(data, av, envp);
		data.pid2 = fork();
		if (data.pid2 < 0)
			ft_print_error_return(ERROR_FORK);
		else if (data.pid2 == 0)
			child2(data, av, envp);
		close_pipe(data);
		close_std(data);
		waitpid(data.pid1, NULL, 0);
		waitpid(data.pid2, NULL, 0);
	}
	else
		ft_print_error_return(ERROR_ARGS);
	return (0);
}
