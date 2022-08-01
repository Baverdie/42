/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:30:22 by baverdie          #+#    #+#             */
/*   Updated: 2022/08/01 18:54:16 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:30:22 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/31 23:10:32 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		argv[i][j] = '\0';
		write(1, "\n", 2);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*temp;
	int	s;

	(void)argc;
	(void)argv;
	s = 1;
	while (s < argc - 1)
	{
		if (ft_strcmp(argv[s], argv[s + 1]))
			{
				temp = argv[s];
				argv[s] = argv[s + 1];
				argv[s + 1] = temp;
				s = 1;
			}
		else
			s++;
	}
	ft_print_params(argc, argv);
	return (0);
}

