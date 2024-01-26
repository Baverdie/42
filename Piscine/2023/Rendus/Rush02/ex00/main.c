/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:22:00 by vgodart           #+#    #+#             */
/*   Updated: 2023/07/30 14:00:45 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	ft_print_nbr(ft_parsing_file("numbers.dict"), ft_atoi_check(argv[1]));
	ft_putstr("\n");
	return (0);
}
