/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:36:04 by basverdi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/26 15:00:09 by basverdi         ###   ########.fr       */
=======
/*   Updated: 2024/02/21 16:15:32 by basverdi         ###   ########.fr       */
>>>>>>> 65ebafa42360743e10784b295441462a9d178f7a
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
	close(fd1);
	fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 <= 0)
	{
		close(fd2);
		perror(av[4]);
		exit (1);
	}
	close(fd2);
	data->fd_out = fd2;
}

void	close_pipe(t_data data)
{
	close(data.pipe[0]);
	close(data.pipe[1]);
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

<<<<<<< HEAD
void	close_std(void)
{
	close(0);
	close(1);
=======
void	ft_free_vars(int nb, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, nb);
	while (i < nb)
	{
		free(va_arg(arg, char *));
		i++;
	}
	va_end(arg);
>>>>>>> 65ebafa42360743e10784b295441462a9d178f7a
}
