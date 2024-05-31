/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:59:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/31 17:26:05 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_error(char *s)
{
	printf("%s%s%s\n", RED, s, DEFAULT);
	return (0);
}

void	print_status(int id, char *status, long long time)
{
	if (!ft_strncmp(status, TAKE_FORKS, ft_strlen(TAKE_FORKS)))
		printf("%s%lld ms %s%d%s has taken a fork%s\n", YELLOW, time, YELLOW, id + 1, YELLOW, DEFAULT);
	else if (!ft_strncmp(status, EATING, ft_strlen(EATING)))
		printf("%s%lld ms %s%d%s is eating%s\n", GREEN, time, YELLOW, id + 1, GREEN, DEFAULT);
	else if (!ft_strncmp(status, SLEEPING, ft_strlen(SLEEPING)))
		printf("%s%lld ms %s%d%s is sleeping%s\n", CYAN, time, YELLOW, id + 1, CYAN, DEFAULT);
	else if (!ft_strncmp(status, THINKING, ft_strlen(THINKING)))
		printf("%s%lld ms %s%d%s is thinking%s\n", MAGENTA, time, YELLOW, id + 1, MAGENTA, DEFAULT);
	else if (!ft_strncmp(status, DIED, ft_strlen(DIED)))
		printf("%s%lld ms %s%d%s is dead%s\n", RED, time, YELLOW, id + 1, RED, DEFAULT);
	else if (!ft_strncmp(status, FINISH, ft_strlen(FINISH)))
		printf("%sAll philosophers have finished eating%s\n", YELLOW, DEFAULT);
}

void	print_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data.nb_philo)
	{
		printf("Philo[%d] :\n   id = %d\n   meals = %d\n   fork left = %d\n   fork right = %d\n   is dead = %s\n", i + 1, philo[i].id + 1, philo[i].meals, philo[i].fork_l->fork, philo[i].fork_r.fork, philo[i].data.is_dead ? "true" : "false");
		i++;
	}
}