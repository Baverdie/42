/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:10:24 by basverdi          #+#    #+#             */
/*   Updated: 2024/04/30 15:10:59 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	if (size == 0 || nmeb == 0)
		return (malloc(1));
	if ((long long)size < 0 || (long long)nmeb < 0)
		return (NULL);
	array = malloc(size * nmeb);
	if (!array)
		return (NULL);
	while (i < nmeb * size)
	{
		array[i] = '\0';
		i += 1;
	}
	return (array);
}