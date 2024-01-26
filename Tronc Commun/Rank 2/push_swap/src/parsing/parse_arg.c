/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:06:11 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/26 13:50:52 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	parse_str(char	*str)
{
	char	**nb;
	int		i;
	int		j;

	i = 0;
	nb = ft_split(str, ' ');
	while (nb[i])
	{
		j = 0;
		if (ft_strlen(nb[i]) > 1 && nb[i][j] == '-')
			j++;
		while (nb[i][j])
		{
			if (ft_isdigit(nb[i][j]) == 0)
				return (ft_print_errors(NOT_NUMBERS));
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicates_str(char	*str)
{
	char	**nb;
	int		i;
	int		j;

	i = 0;
	nb = ft_split(str, ' ');
	
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_strlen(argv[i]) > 1 && argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (ft_print_errors(NOT_NUMBERS));
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	*tab;

	i = 1;
	tab = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		tab[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (tab[i] == tab[j])
				return (ft_print_errors(NOT_DUPLICATES));
			j++;
		}
		i++;
	}
	return (1);
}
