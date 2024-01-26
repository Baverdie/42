/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:58:00 by basverdi          #+#    #+#             */
/*   Updated: 2023/08/03 14:53:23 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*r;

	i = 0;
	while (src[i])
		i++;
	r = malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i])
	{
		r[i] = src[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab[i] == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i].str = av[i];
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
