/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:36:47 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:42 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	ft_close_pipe(t_data data)
{
	close(data.pipe[0]);
	close(data.pipe[1]);
}

void	ft_close_fd(t_data data)
{
	close(data.fd_in);
	close(data.fd_out);
}

void	ft_close_exit(void)
{
	close(0);
	close(1);
}

void	ft_close_all(t_data data)
{
	ft_close_exit();
	ft_close_fd(data);
	ft_close_pipe(data);
}

void	ft_close(t_data data, int nb, ...)
{
	va_list			args;
	t_close_type	type;

	va_start(args, nb);
	while (nb--)
	{
		type = va_arg(args, t_close_type);
		if (type == CLOSE_FD)
			ft_close_fd(data);
		if (type == CLOSE_PIPE)
			ft_close_pipe(data);
		if (type == CLOSE_STD)
			ft_close_exit();
		if (type == CLOSE_ALL)
			ft_close_all(data);
		if (type == EXIT)
		{
			va_end(args);
			exit(1);
		}
	}
	va_end(args);
}
