/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:56:20 by bastienverd       #+#    #+#             */
/*   Updated: 2024/03/01 15:59:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
