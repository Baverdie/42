/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:04:56 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/27 17:32:59 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "includes/libs.h"
# include "includes/structs.h"
# include "includes/utils.h"
# include "includes/functions.h"

#define ERR_MUTEX "mutex init failed"

# define TAKE_FORKS "has taken a fork"
// # define TAKE_RIGHT_FORKS "has taken the right fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "is died"
# define END "All philosophers have eaten enough"
# define FINISH "The simulation is over"

#define DEFAULT "\001\033[m\002"
#define BLACK "\001\e[0;30m\002"
#define RED "\001\e[1;31m\002"
#define GREEN "\001\e[1;38;5;2m\002"
#define YELLOW "\001\e[1;33m\002"
#define BLUE "\001\e[1;34m\002"
#define MAGENTA "\001\e[1;35m\002"
#define CYAN "\001\e[1;38;5;31m\002"
#define WHITE "\001\e[1;97m\002"
#define GREY "\001\e[1;90m\002"

# define INTMAX "2147483647"
# define INTMIN "2147483648"
# define LLMAX "9223372036854775807"
# define LLMIN "9223372036854775808"

#endif