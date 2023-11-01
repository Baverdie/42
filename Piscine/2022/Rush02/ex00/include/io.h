/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:18:16 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 18:04:17 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "error.h"
# include <stddef.h>

t_error	ft_atoui(char *nptr, unsigned int *result);
t_error	ft_parse_uint(char *str, unsigned int *result);
char	*ft_trim(char *str);

#endif // IO_H
