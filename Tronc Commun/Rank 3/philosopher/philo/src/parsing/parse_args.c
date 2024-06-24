/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:04:49 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/24 15:46:30 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (av[i][j] < '0' || av[i][j] > '9')
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}
