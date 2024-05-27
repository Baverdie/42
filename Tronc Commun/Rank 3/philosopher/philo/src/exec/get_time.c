/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:59:26 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/27 17:31:58 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time(long long start)
{
	struct timeval	time;
	long long		time_ms;

	gettimeofday(&time, NULL);
	time_ms = time.tv_sec * 1000 + time.tv_usec / 1000 - start;
	return (time_ms);
}

void	set_start(long long *start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*start = time.tv_sec * 1000 + time.tv_usec / 1000;
}
