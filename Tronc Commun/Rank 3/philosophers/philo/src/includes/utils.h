/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:06:55 by basverdi          #+#    #+#             */
/*   Updated: 2024/06/24 18:33:22 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../philo.h"

int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmeb, size_t size);
size_t		ft_strlen(const char *s);
t_bool		ft_overflow(char *s, ...);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_exit(t_data *data);
void		print_status(char *status, t_philo *philo);
int			print_error(char *s);
void		ft_free_alloc(t_data *data);
void		check_meals(t_philo *philo);
t_bool		taken_forks(t_philo *philo);
t_bool		drop_forks(t_philo *philo);

#endif
