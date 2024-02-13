/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:35:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/13 18:13:36 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_max(t_stack **stack)
{
	t_stack *tmp;
	int	max;
	
	tmp = *stack;
	max = tmp->nb;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min(t_stack **stack)
{
	t_stack *tmp;
	int	min;
	
	tmp = *stack;
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

void	simple_sort(t_stack **stack)
{
	int	max;

	max = find_max(stack);
	if ((*stack)->nb == max)
		ra(stack);
	else if ((*stack)->next->nb == max)
		rra(stack);
	if ((*stack)->nb > (*stack)->next->nb)
		sa(stack);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	int	min;
	int	count;

	tmp = *stack_a;
	min = find_min(stack_a);
	count = 0;
	while (tmp->nb != min)
	{
		tmp = tmp->next;
		count++;
	}
	if (count >= 3)
	{
		while ((*stack_a)->nb != min)
			rra(stack_a);
	}
	else if (count >= 1)
	{
		while ((*stack_a)->nb != min)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	simple_sort(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	
}
