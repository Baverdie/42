/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:55:56 by bastienverd       #+#    #+#             */
/*   Updated: 2024/03/11 17:24:16 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stksize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_stklast(head);
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stksize(*stack_a) < 2) || (ft_stksize(*stack_b) < 2))
		return (1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
