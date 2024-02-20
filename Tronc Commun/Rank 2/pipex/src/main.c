/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:05:45 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/19 17:01:09 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac == 5)
	{
		get_fds(&data, av);
		parse_args(av, envp);
	}
	else
		ft_print_error(ERROR_ARGS);
	return (0);
}
