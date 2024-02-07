/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:34:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/07 16:31:47 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*dest;
	t_stack	*src;
	t_stack	*tmp;

	if (ft_lstsize(*stack_src) == 0)
		return (0);
	dest = *stack_dest;
	src = *stack_src;
	tmp = src->next;
	src->next = dest;
	*stack_dest = src;
	*stack_src = tmp;
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return (0);
}
