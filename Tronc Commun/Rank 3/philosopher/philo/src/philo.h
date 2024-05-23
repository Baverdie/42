/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:04:56 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/23 15:29:43 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "includes/libs.h"
# include "includes/structs.h"
# include "includes/parsing.h"
# include "includes/utils.h"
# include "includes/functions.h"

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

# define ERR_MUTEX "mutex init failed"

# define INTMAX "2147483647"
# define INTMIN "2147483648"
# define LLMAX "9223372036854775807"
# define LLMIN "9223372036854775808"

#endif