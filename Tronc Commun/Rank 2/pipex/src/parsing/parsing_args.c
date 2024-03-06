/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:53 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/06 18:07:04 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**paths;
	char	*tmp;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	path = ft_strdup("");
	tmp = ft_strjoin("/", cmd);
	while (paths && paths[i] && path && access(path, F_OK))
	{
		free(path);
		path = ft_strjoin(paths[i], tmp);
		i++;
	}
	free(tmp);
	ft_free(paths);
	return (path);
}
