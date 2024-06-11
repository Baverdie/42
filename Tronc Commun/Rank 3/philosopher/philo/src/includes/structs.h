/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:27:08 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/02 04:12:11 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

struct s_data;

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				count_meals;
	t_bool			status;
	int				eating;
	u_int64_t		time_to_die;
	pthread_t		t1;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				nb_philo;
	int				nb_meals;
	t_bool			dead;
	int				finished;
	t_philo			*philos;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
} t_data;

#endif