/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/21 10:04:05 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	check_cmd(char	**path, char **av)
{
	int	i;
	char	*full_path;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(tmp, av[2]);
		free(tmp);
		if (access(full_path, F_OK) == 0)
			ft_printf("%s is existing\n", av[2]);
		i++;
		free(full_path);
	}
	return (0);
}

void	parse_args(char **av, char **envp)
{
	int	i;
	char	**paths;

	i = 0;
	paths = NULL;
	if (access(av[2], F_OK) == -1 && access(av[3], F_OK) == -1 && envp != NULL)
	{
		while (ft_strncmp(envp[i], "PATH=", 5))
			i++;
		paths = ft_split(envp[i] + 5, ':');
		if (!paths)
			exit (1);
		check_cmd(paths, av);
		ft_free(paths);
	}
}

char	*get_path(char **envp, char *cmd)
{
	int	i;
	char	*path;
	char	**paths;
	char	*tmp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		if (access(path, F_OK) == 0)
		{
			ft_free(paths);
			free(tmp);
			return (path);
		}
		free(path);
		free(tmp);
		i++;
	}
	return (NULL);
}
