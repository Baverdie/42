/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:29:34 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/26 10:30:09 by basverdi         ###   ########.fr       */
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
