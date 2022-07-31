/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:37:05 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 09:08:49 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define UPPERCASE_OFFSET 32

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + UPPERCASE_OFFSET);
	return (c);
}
