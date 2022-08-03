/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:27:18 by baverdie          #+#    #+#             */
/*   Updated: 2022/08/04 00:27:24 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	j;

	argc--;
	while (argc > 0)
	{
		j = 0;
		while (argv[argc][j])
		{
			write(1, &argv[argc][j], 1);
			j++;
		}
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
