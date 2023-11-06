/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:11:04 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 09:12:58 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(const char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	while (*s++)
		write(1, s - 1, 1);
}
