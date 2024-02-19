/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:45 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/19 14:19:07 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	i;
	char	*full_path;
	char	*tmp;

	i = 0;
	path = NULL;
	if (ac == 5)
	{
		check_cmd(char **av, char **envp);
		i = 0;
		while (path[i])
		{
			printf("%s\n", path[i]);
			tmp = ft_strjoin(path[i], "/");
			full_path = ft_strjoin(tmp, av[1]);
			free(tmp);
			if (access(full_path, F_OK) == 0)
				printf("%s is existing\n", av[1]);
			i++;
			free(full_path);
		}
		ft_free(path);
	}
	else
		ft_print_error(ERROR_ARGS);
	return (0);
}
