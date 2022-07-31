/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:09:41 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/30 22:37:54 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	ERROR = 1,
	OK = 0
}	t_error;

t_error	ft_errort(char *type, char *reason);
t_error	ft_error(char *reason);
t_error	ft_errord(char *reason);

#endif // ERROR_H
