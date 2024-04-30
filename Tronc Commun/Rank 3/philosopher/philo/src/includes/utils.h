/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:06:55 by basverdi          #+#    #+#             */
/*   Updated: 2024/04/30 15:38:18 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

long long	ft_atoll(char *s);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmeb, size_t size);
size_t		ft_strlen(const char *s);
t_bool		ft_overflow(char *s, char *type);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif