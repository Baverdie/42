/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:42:23 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 08:59:36 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define UPPERCASE_OFFSET 32

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - UPPERCASE_OFFSET);
	return (c);
}
