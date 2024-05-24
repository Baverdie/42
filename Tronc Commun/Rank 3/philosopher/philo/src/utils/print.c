/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:59:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/24 17:09:33 by basverdi         ###   ########.fr       */
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
	if (!ft_strncmp(status, TAKE_LEFT_FORKS, ft_strlen(TAKE_LEFT_FORKS)))
		printf("%sPhilo[%s%d%s] has taken a left fork at the %0.8lld sec%s\n", RED, YELLOW, id, RED, time, DEFAULT);
	else if (!ft_strncmp(status, TAKE_RIGHT_FORKS, ft_strlen(TAKE_RIGHT_FORKS)))
		printf("%sPhilo[%s%d%s] has taken a right fork at the %0.8lld sec%s\n", RED, YELLOW, id, RED, time, DEFAULT);
	else if (!ft_strncmp(status, EATING, ft_strlen(EATING)))
		printf("%sPhilo[%s%d%s] is eating at the %0.8lld sec%s\n", GREEN, YELLOW, id, GREEN, time, DEFAULT);
	else if (!ft_strncmp(status, SLEEPING, ft_strlen(SLEEPING)))
		printf("%sPhilo[%s%d%s] is sleeping at the %0.8lld sec%s\n", CYAN, YELLOW, id, CYAN, time, DEFAULT);
	else if (!ft_strncmp(status, THINKING, ft_strlen(THINKING)))
		printf("%sPhilo[%s%d%s] is thinking at the %0.8lld sec%s\n", MAGENTA, YELLOW, id, MAGENTA, time, DEFAULT);
	else if (!ft_strncmp(status, DIED, ft_strlen(DIED)))
		printf("%sPhilo[%s%d%s] is dead at the %0.8lld sec%s\n", RED, YELLOW, id, RED, time, DEFAULT);
	else if (!ft_strncmp(status, FINISH, ft_strlen(FINISH)))
		printf("%sAll philosophers have eaten%s\n", GREEN, DEFAULT);
}

void	print_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data.nb_philo)
	{
		printf("Philo[%d] :\n   id = %d\n   meals = %d\n   fork left = %d\n   fork right = %d\n   is dead = %d\n   all meals = %d\n", i, philo[i].id, philo[i].meals, philo[i].fork_l->fork, philo[i].fork_r.fork, philo[i].data.is_dead, philo[i].data.all_meals);
		i++;
	}
}