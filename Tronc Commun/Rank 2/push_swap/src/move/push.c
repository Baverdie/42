/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:34:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/01/26 18:37:56 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push(t_stack *stack_dest, t_stack *stack_src)
{
	t_stack *dest;

	if (ft_lstsize(stack_src) == 0)
		return (0);
	dest = stack_dest;
	while (dest)
	{
		if (dest->next->next == NULL)
		{
			dest->next = NULL;
			break ;
		}
		dest = dest->next;
	}
	*stack_dest = *stack_src;
	return (0);
}

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	return (0);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	return (0);
}