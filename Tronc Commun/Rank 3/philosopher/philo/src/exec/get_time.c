/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:59:26 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/02 04:14:39 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

u_int64_t	get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (print_error("Error: gettimeofday failed", NULL));
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int ft_usleep(useconds_t time)
{
	u_int64_t start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
