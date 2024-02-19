/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/19 15:32:13 by basverdi         ###   ########.fr       */
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
		full_path = ft_strjoin(tmp, av[1]);
		free(tmp);
		if (access(full_path, F_OK) == 0)
			printf("%s is existing\n", av[1]);
		i++;
		free(full_path);
	}
	return (0);
}

int	parse_args(char **av, char **envp)
{
	int	i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
		}
		i++;
	}
	if (!path)
		return (1);
	check_cmd(path, av);
	ft_free(path);
	return (0);
}
