/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:27:08 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/23 16:19:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_fork
{
	t_bool			fork;
	pthread_mutex_t	fork_m;
} t_fork;

typedef struct s_philo
{
	int			id;
	int			meals;
	int			die;
	t_fork		fork_r;
	t_fork		*fork_l;
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_meals;
	int		nb_philo;
	t_philo	**philo;
}	t_data;

#endif