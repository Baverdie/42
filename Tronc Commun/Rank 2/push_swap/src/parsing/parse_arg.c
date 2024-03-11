/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:06:11 by bastienverd       #+#    #+#             */
/*   Updated: 2024/03/11 17:16:10 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_empty(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	if (!argv[i])
		return (1);
	while (argv[i])
	{
		j = 0;
		count = 0;
		if (ft_strlen(argv[i]) == 0)
			return (1);
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				count++;
			j++;
		}
		if (count == ft_strlen(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_duplicates(long nb, char **args, int i)
{
	long	tmp;

	i++;
	while (args[i])
	{
		tmp = ft_atoll(args[i]);
		if (nb == tmp)
			return (1);
		i++;
	}
	return (0);
}

int	check_all(long tmp, char **args, int i, int argc)
{
	if (ft_isnum(args[i]))
	{
		if (argc == 2)
			ft_free(args);
		ft_print_errors();
		return (1);
	}
	if (tmp > 2147483647 || tmp < -2147483648 || ft_strlen(args[i]) > 11)
	{
		if (argc == 2)
			ft_free(args);
		ft_print_errors();
		return (1);
	}
	if (ft_check_duplicates(tmp, args, i))
	{
		if (argc == 2)
			ft_free(args);
		ft_print_errors();
		return (1);
	}
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	args = argv;
	if (ft_empty(args))
		ft_print_errors();
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		i = 1;
	while (args[i])
	{
		tmp = ft_atoll(args[i]);
		if (check_all(tmp, args, i, argc))
			exit(0);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
