/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:36:04 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/21 10:05:25 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	ft_print_error(char *err)
{
	ft_printf("%s%s\n", TITLE_ERROR, err);
}

int	ft_print_error_return(char *err)
{
	ft_printf("%s%s\n", TITLE_ERROR, err);
	return (0);
}

void	get_fds(t_data *data, char **av)
{
	int	fd1;
	int	fd2;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 <= 0)
	{
		perror(av[1]);
		exit (1);
	}
	data->fd_in = fd1;
	fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 <= 0)
	{
		perror(av[4]);
		exit (1);
	}
	data->fd_out = fd2;
}

void	close_pipe(t_data *data)
{
	close(data->pipe[0]);
	close(data->pipe[1]);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
