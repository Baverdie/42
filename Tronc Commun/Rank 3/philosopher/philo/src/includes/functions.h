/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:12:59 by bastienverd       #+#    #+#             */
/*   Updated: 2024/06/02 04:46:05 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

// Init functions
t_bool		init(int ac, char **av, t_data *data);
t_bool		thread_init(t_data *data);

// Parsing functions
t_bool		check_input(char **av);

// Execution functions
void		*routine(void *arg);
u_int64_t	get_time(void);
int			ft_usleep(useconds_t time);

#endif