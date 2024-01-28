/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:29:34 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/26 19:25:12 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	add_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;

	i = 1;
	while (i <= argc - 1)
	{
		stack_a->nb = ft_atoi(argv[i]);
		if (i + 1 <= argc - 1)
			stack_a->next = ft_calloc(1, sizeof(t_stack));
		stack_a = stack_a->next;
		i++;
	}
}

void	add_stack_str(char *str, t_stack *stack_a)
{
	int		i;
	char	**nb;

	nb = ft_split(str, ' ');
	i = 0;
	while (nb[i])
	{
		stack_a->nb = ft_atoi(nb[i]);
		if (nb[i + 1])
			stack_a->next = ft_calloc(1, sizeof(t_stack));
		stack_a = stack_a->next;
		i++;
	}
}
