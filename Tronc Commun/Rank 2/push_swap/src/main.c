/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:52:33 by bastienverd       #+#    #+#             */
/*   Updated: 2023/12/24 23:08:15 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int    ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_pileadd(t_stack **pile, t_stack *new)
{
	if (pile && new)
	{
		new->next = *pile;
		*pile = new;
	}
}

t_stack	*ft_pilenew(int nb)
{
	t_stack	*new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->value = nb;
	new->next = NULL;
	return (new);
}

void	ft_pileprint(t_stack *pile)
{
	while (pile)
	{
		ft_putnbr_fd(pile->value, 1);
		ft_putchar_fd('\n', 1);
		pile = pile->next;
	}
}

void	ft_pilefree(t_stack **pile)
{
	t_stack	*tmp;

	while (*pile)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		free(tmp);
	}
}

int		main(int argc, char **argv)
{
	t_stack	*pile_a;
	t_stack	*pile_b;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	pile_a = NULL;
	pile_b = NULL;
	while (i < argc)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		if (ft_isnumber(argv[i]) == 0)
		{
			print_errors();
			ft_debug(argv[i], i, 1);
			return (0);
		}
		if (ft_atoi(argv[i]) <= -2147483648 || ft_atoi(argv[i]) >= 2147483647)
		{
			print_errors();
			ft_debug(argv[i], i, 2);
			return (0);
		}
		ft_pileadd(&pile_a, ft_pilenew(ft_atoi(argv[i])));
		i++;
	}
	ft_pileprint(pile_a);
	ft_pileprint(pile_b);
	ft_pilefree(&pile_a);
	ft_pilefree(&pile_b);
	return (0);
}
