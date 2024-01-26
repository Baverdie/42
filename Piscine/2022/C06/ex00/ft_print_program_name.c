/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:44:21 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/31 08:19:31 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j;

	(void) argc;
	j = 0;
	while (argv[0][j])
	{
		write(1, &argv[0][j], 1);
		j++;
	}
	return (0);
}
