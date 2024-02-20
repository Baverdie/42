/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:36:04 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/19 17:02:53 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	ft_print_error(char *err)
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
		printf("bash: no such file or directory: %s\n", av[1]);
	data->fd_in = fd1;
	fd2 = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0000644);
	if (fd2 <= 0)
		printf("bash: no such file or directory: %s\n", av[4]);
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
