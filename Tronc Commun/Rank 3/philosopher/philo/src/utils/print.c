/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:59:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/18 16:41:09 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_error(char *s)
{
	printf("%s%s%s\n", RED, s, DEFAULT);
	return (1);
}

void	print_color(u_int64_t time, t_philo *philo, char *status)
{
	if (ft_strncmp(status, EATING, ft_strlen(EATING)) == 0)
		printf("%s%lums %s%d %s%s%s\n", GREEN, time, YELLOW, philo->id, \
			GREEN, status, DEFAULT);
	else if (ft_strncmp(status, SLEEPING, ft_strlen(SLEEPING)) == 0)
		printf("%s%lums %s%d %s%s%s\n", CYAN, time, YELLOW, philo->id, \
			CYAN, status, DEFAULT);
	else if (ft_strncmp(status, THINKING, ft_strlen(THINKING)) == 0)
		printf("%s%lums %s%d %s%s%s\n", MAGENTA, time, YELLOW, philo->id, \
			MAGENTA, status, DEFAULT);
	else if (ft_strncmp(status, FORK, ft_strlen(FORK)) == 0)
		printf("%s%lums %s%d %s%s%s\n", GREY, time, YELLOW, philo->id, GREY, \
			status, DEFAULT);
}

void	print_status(char *status, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->print);
	time = get_time() - philo->data->start_time;
	if (ft_strncmp(status, DIED, ft_strlen(DIED)) == 0 \
		&& philo->data->dead == 0)
	{
		printf("%s%lums %s%d %s%s%s\n", RED, time, YELLOW, philo->id, RED, \
			status, DEFAULT);
		philo->data->dead = 1;
	}
	if (!philo->data->dead)
		print_color(time, philo, status);
	pthread_mutex_unlock(&philo->data->print);
}
