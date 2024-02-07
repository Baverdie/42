/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:34:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/02/05 18:13:18 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push(t_stack *stack_dest, t_stack *stack_src)
{
	t_stack *dest;
	t_stack *tmp;

	if (ft_lstsize(stack_src) == 0)
		return (0);
	dest = stack_dest;
	tmp = stack_src;
	dest = dest->next;
	(void)tmp;
	stack_src = stack_src->next;
	return (0);
}

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return (0);
}