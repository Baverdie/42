/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:29:34 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/25 16:39:44 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	add_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		stack_a->nb = ft_atoi(argv[i]);
		stack_a->next = malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
	printf("stack_a->nb = %d\n", stack_a->nb);
}
