/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:24:37 by bastienverd       #+#    #+#             */
/*   Updated: 2023/12/25 00:48:12 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static int	contains(int nb, char **argv, int i)
// {
// 	i++;
// 	while (argv[i])
// 	{
// 		if (ft_atoi(argv[i]) == nb)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

void	ft_debug(char *str, int i, int j)
{
	ft_putendl_fd(str, 2);
}

void	print_errors()
{
	ft_putendl_fd("Error", 2);
}
