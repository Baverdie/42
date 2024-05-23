/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:06:55 by basverdi          #+#    #+#             */
/*   Updated: 2024/05/23 15:04:00 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

long long	ft_atoll(char *s);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmeb, size_t size);
size_t		ft_strlen(const char *s);
t_bool		ft_overflow(char *s, ...);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_bool		ft_free(t_data *data);
t_bool		ft_free_philo(t_data *data);
char		*ft_vjoin(size_t nb_str, char *sep, ...);
void		print_philo(t_data *data); //delete

#endif