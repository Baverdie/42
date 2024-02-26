/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:22:06 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/26 17:54:54 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	ft_print_error_return(char *err)
{
	ft_putstr_fd(TITLE_ERROR, 2);
	ft_putstr_fd(err, 2);
	return (0);
}

void	get_fds(t_data *data, char **av)
{
	int	fd1;
	int	fd2;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 <= 0)
	{
		close(fd1);
		perror(av[1]);
		exit (1);
	}
	data->fd_in = fd1;
	fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 <= 0)
	{
		close(fd2);
		perror(av[4]);
		exit (1);
	}
	data->fd_out = fd2;
}

void	close_pipe(t_data data)
{
	close(data.pipe[0]);
	close(data.pipe[1]);
	close(data.fd_in);
	close(data.fd_out);
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

void	close_std()
{
	close(0);
	close(1);
	close(2);
}
