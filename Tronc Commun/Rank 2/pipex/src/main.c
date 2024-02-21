/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:45 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/21 09:58:56 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child1(t_data data, char **av, char **envp)
{
	dup2(data.fd_in, 0);
	dup2(data.pipe[1], 1);
	close(data.pipe[0]);
	data.cmd = ft_split(av[2], ' ');
	data.cmd_path = get_path(envp, data.cmd[0]);
	if (data.cmd_path == NULL)
	{
		ft_print_error(ERROR_CMD);
		exit (1);
	}
	execve(data.cmd_path, data.cmd, envp);
	ft_print_error(ERROR_CMD);
}

void	child2(t_data data, char **av, char **envp)
{
	dup2(data.pipe[0], 0);
	dup2(data.fd_out, 1);
	close(data.pipe[1]);
	data.cmd = ft_split(av[3], ' ');
	data.cmd_path = get_path(envp, data.cmd[0]);
	if (data.cmd_path == NULL)
	{
		ft_print_error(ERROR_CMD);
		exit (1);
	}
	execve(data.cmd_path, data.cmd, envp);
	ft_print_error(ERROR_CMD);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac == 5)
	{
		get_fds(&data, av);
		if (pipe(data.pipe) == -1)
			ft_print_error(ERROR_PIPE);
		data.pid1 = fork();
		if (data.pid1 < 0)
			ft_print_error(ERROR_FORK);
		else if (data.pid1 == 0)
			child1(data, av, envp);
		data.pid2 = fork();
		if (data.pid2 < 0)
			ft_print_error(ERROR_FORK);
		else if (data.pid2 == 0)
			child2(data, av, envp);
		close_pipe(&data);
		waitpid(data.pid1, NULL, 0);
		waitpid(data.pid2, NULL, 0);
	}
	else
		ft_print_error(ERROR_ARGS);
	return (0);
}
