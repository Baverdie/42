/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:24:37 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/25 16:37:14 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_print_errors(char *err)
{
	printf("%s%s", TITLE_ERROR, err);
	return (0);
}

void	ft_print_stack(t_stack *stack)
{
	while (stack->next)
	{
		printf("%d\n", stack->nb);
		stack = stack->next;
	}
}

void	ft_print_double_stack(t_stack *stack_a, t_stack *stack_b)
{
	printf("\n-----\t\t-----\n");
	printf("| A |\t\t| B |\n");
	printf("-----\t\t-----\n");
	while (stack_a->next || stack_b->next)
	{
		if (stack_a->next)
		{
			printf("| %d |\t\t", stack_a->nb);
			stack_a = stack_a->next;
		}
		else
			printf("\t\t");
		if (stack_b->next)
		{
			printf("| %d |\n", stack_b->nb);
			stack_b = stack_b->next;
		}
		else
			printf("\n");
	}
	printf("-----\t\t-----\n");
	printf("\n");
}