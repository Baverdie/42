/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:14:57 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 23:26:30 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <unistd.h>

#define BETTER_ERROR 0

#if BETTER_ERROR

t_error	ft_errort(char *type, char *reason)
{
	ft_putstr(type);
	ft_putstr("!\n");
	ft_putstr("Reason: ");
	ft_putstr(reason);
	ft_putstr("\n");
	return (ERROR);
}

#else

t_error	ft_errort(char *type, char *reason)
{
	(void) reason;
	ft_putstr(type);
	ft_putstr("!\n");
	return (ERROR);
}

#endif

t_error	ft_error(char *reason)
{
	return (ft_errort("Error", reason));
}

t_error	ft_errord(char *reason)
{
	return (ft_errort("Dict Error", reason));
}
