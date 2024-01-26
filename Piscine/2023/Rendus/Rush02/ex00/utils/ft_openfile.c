/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:53:01 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/30 14:02:53 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_openfile(int *tab_int, char *path)
{
	tab_int[0] = open(path, O_RDONLY);
	if (tab_int[0] < 0)
	{
		write(1, "Error", 5);
		exit(1);
	}
}
