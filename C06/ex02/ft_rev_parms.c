/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_parms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:02:10 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/31 09:30:18 by baverdie         ###   ########.fr       */
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
