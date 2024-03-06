/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:06 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/06 18:00:00 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	ft_print_error(char *err)
{
	ft_putstr_fd(TITLE_ERROR, 2);
	ft_putstr_fd(err, 2);
	exit(1);
}

void	ft_exit_error(char *err, t_data data)
{
	ft_putstr_fd(TITLE_ERROR, 2);
	ft_putstr_fd(err, 2);
	ft_close(data, 2, CLOSE_FD, EXIT);
}

void	get_fds(t_data *data, char **av)
{
	int	fd1;
	int	fd2;

	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd1 <= 0)
	{
		close(fd2);
		perror(av[1]);
		exit (1);
	}
	data->fd_in = fd1;
	if (fd2 <= 0)
	{
		close(data->fd_in);
		perror(av[4]);
		exit (1);
	}
	data->fd_out = fd2;
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
