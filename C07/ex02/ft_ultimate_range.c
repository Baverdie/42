/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 07:16:51 by baverdie          #+#    #+#             */
/*   Updated: 2022/08/04 07:54:07 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = ((0));
		return (0);
	}
	else
	{
		*range = malloc((max - min) * sizeof(int));
		if (range == NULL)
			return (-1);
	}
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}
