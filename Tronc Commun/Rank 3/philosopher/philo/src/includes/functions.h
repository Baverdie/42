/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:12:59 by bastienverd       #+#    #+#             */
/*   Updated: 2024/05/24 17:03:29 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

// Init functions
t_bool	ft_init_philo(t_philo *philo);

// Parsing functions
t_bool parse_args(int ac, char **av, t_philo *philo);

// Execution functions
void		exec(t_philo *philo);
long long	get_time(void);

#endif