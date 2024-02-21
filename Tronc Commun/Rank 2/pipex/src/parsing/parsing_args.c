/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/21 14:22:48 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*get_path(char **envp, char *cmd)
{
	int	i;
	char	*path;
	char	**paths;
	char	*tmp;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
		{
			i++;
			continue;
		}
		path = ft_strjoin(tmp, cmd);
		if (path && access(path, F_OK) == 0)
		{
			ft_free(paths);
			free(tmp);
			return (path);
		}
		ft_free_vars(2, path, tmp);
		i++;
	}
	ft_free(paths);
	return (NULL);
}
