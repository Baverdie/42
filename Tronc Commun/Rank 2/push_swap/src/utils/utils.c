/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:24:37 by bastienverd       #+#    #+#             */
/*   Updated: 2024/01/26 10:54:31 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_print_errors(char *err)
{
	printf("%s%s", TITLE_ERROR, err);
	return (0);
}

void	graph(t_stack *stack)
{
	printf("\n-----\n| A |\n-----\n");
	ft_print_stack(stack);
	printf("-----\n");
}

void	graph_double(t_stack *stack_a, t_stack *stack_b)
{
	printf("\n-----\t\t-----\n| A |\t\t| B |\n-----\t\t-----\n");
	ft_print_double_stack(stack_a, stack_b);
	printf("-----\t\t-----\n\n");
}

void	ft_print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	printf("| %d |\n", stack->nb);
	ft_print_stack(stack->next);
}

void	ft_print_double_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->next && !stack_b->next)
	{
		if (stack_a->nb)
		{
			printf("| %d |\t\t", stack_a->nb);
			stack_a = stack_a->next;
		}
		else
			printf("|   |\t\t");
		if (stack_b->nb)
		{
			printf("| %d |\n", stack_b->nb);
			stack_b = stack_b->next;
		}
		else
			printf("|   |\n");
		return ;
		}
	if (stack_a->nb)
	{
		printf("| %d |\t\t", stack_a->nb);
		stack_a = stack_a->next;
	}
	else
		printf("|   |\t\t");
	if (stack_b->nb)
	{
		printf("| %d |\n", stack_b->nb);
		stack_b = stack_b->next;
	}
	else
		printf("|   |\n");
	ft_print_double_stack(stack_a, stack_b);
}
